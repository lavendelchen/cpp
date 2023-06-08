/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 19:01:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &orig) {
	(void)orig;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) { }
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
PmergeMe::~PmergeMe() { }

/* -------------------------------- PRIVATE METHODS -------------------------------- */
void	PmergeMe::mergeMe_deque(char* input[]) {
	SortDeque	sequence;
	SortDeque	mainChain;

	inputParsing(input, sequence);
	printSequence("Before", sequence);
	if (!isSorted(sequence)) { // should we use? not sure
		std::cout << "IS NOT SORTED\n";
		FJMI(sequence, mainChain);
	}
	printSequence("After", mainChain);
}

void	PmergeMe::mergeMe_vector(char* input[]) {
	(void)input;
}

void	PmergeMe::inputParsing(char* input[], SortDeque& sequence) {
	std::stringstream	inputStream;

	long long	buffer;
	for (int i = 0, j; input[i] != NULL; i++) {
		for (j = 0; input[i][j] != '\0'; j++) {
			if (!std::isdigit(input[i][j]))
				throw std::logic_error("Error: Each argument should be a positive integer");
		}
		if (j > 10 || j <= 0)
			throw std::logic_error("Error: Either you gave a too big number or an empty string");
		inputStream.str(input[i]);
		inputStream >> buffer;
		inputStream.clear();
		if (buffer > INT_MAX)
			throw std::logic_error("Error: Integers must be in int range");

		std::pair<int,int>	newElement(buffer, 0);
		if (std::find(sequence.begin(), sequence.end(), newElement) != sequence.end())
			throw std::logic_error("Error: No duplicates please");
		sequence.push_back(newElement);
	}
}

void	PmergeMe::printSequence(std::string printBefore, SortDeque& sequence) {
	std::cout << printBefore << ":	";
	for (SortDeque::const_iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << ' ' << i->first;
	}
	std::cout << '\n';
}

bool	PmergeMe::isSorted(SortDeque& sequence) {
	SortDeque::const_iterator i = sequence.begin();
	SortDeque::const_iterator after_i = ++sequence.begin();
	SortDeque::const_iterator end = sequence.end();

	for (;after_i != end; i++, after_i++) {
		if (i->first >= after_i->first)
			return (false);
	}
	return (true);
}

void	PmergeMe::FJMI(SortDeque& sequence, SortDeque& mainChain) { // need pair for mainChain?
	SortDeque greaterSequence = sortPairs(sequence);
	FJMI(greaterSequence, mainChain);
}

SortDeque	PmergeMe::sortPairs(SortDeque& sequence) {
	SortDeque	greaterSequence;

	SortDeque::iterator sortFirst = sequence.begin();
	SortDeque::iterator sortSecond = ++sequence.begin();
	SortDeque::iterator end;
	switch (sequence.size() % 2) {
		case 0: end = sequence.end(); break;
		case 1: end = --sequence.end(); break;
	}

	for (; sortFirst != end; sortFirst+=2, sortSecond+=2) {
		if (sortFirst->first < sortSecond->first) {
			sortFirst->second = sortSecond->first; // or index it, not sure yet
			greaterSequence.push_back(*sortSecond);
		}
		else {
			sortSecond->second = sortFirst->first; // or index it, not sure yet
			greaterSequence.push_back(*sortFirst);
		}
	}
	return (greaterSequence);
}

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	PmergeMe::mergeMe(char* input[]) {
	//maybe do template or overload?
	mergeMe_deque(input);
	//mergeMe_vector(input);
	//std::cout << "Before:	";
	//for (int i = 0; input[i] != NULL; i++) {
	//	std::cout << input[i] << ' ';
	//}
	//std::cout << '\n';
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
