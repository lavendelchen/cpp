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
	printSequence("After", sequence);
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
		for (SortDeque::iterator i = sequence.begin(); i != sequence.end(); i++) {
			if ((*i)->value == buffer)
				throw std::logic_error("Error: No duplicates please");
		}

		ValueData* newElement = new ValueData;
		newElement->value = buffer;
		newElement->higher = NULL;
		sequence.push_back(newElement);
	}
}

void	PmergeMe::printSequence(std::string printBefore, SortDeque& sequence) {
	std::cout << printBefore << ":	";
	for (SortDeque::const_iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << ' ' << (*i)->value;
	}
	std::cout << '\n';
}

bool	PmergeMe::isSorted(SortDeque& sequence) {
	SortDeque::const_iterator i = sequence.begin();
	SortDeque::const_iterator after_i = ++sequence.begin();
	SortDeque::const_iterator end = sequence.end();

	for (;after_i != end; i++, after_i++) {
		if ((*i)->value >= (*after_i)->value)
			return (false);
	}
	return (true);
}

void	PmergeMe::FJMI(SortDeque& sequence, SortDeque& mainChain) { // need pair for mainChain?
	SortDeque greaterSequence;

	makePairs(sequence, greaterSequence); // put in if as well?
	std::cout << "\n\nNEW ITERATION\n";
	for (SortDeque::iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout	<< "\n[" << (*i)->value << "]: "
					<< "HIGHER: " << ((*i)->higher == NULL? -1 : (*i)->higher->value)
					<< " LOWER: ";
		for (SortDeque::iterator j = (*i)->lower.begin(); j != (*i)->lower.end(); j++) {
			std::cout << (*j)->value << ' ';
		}
	}
	std::cout << '\n';
	if (sequence.size() >= 2)
		FJMI(greaterSequence, mainChain);
	//binaryInsert(sequence, mainChain);
}

void	PmergeMe::makePairs(SortDeque& sequence, SortDeque& greaterSequence) {
	SortDeque::iterator sortFirst = sequence.begin();
	SortDeque::iterator sortSecond = ++sequence.begin();
	SortDeque::iterator end;
	switch (sequence.size() % 2) {
		case 0: end = sequence.end(); break;
		case 1: end = --sequence.end(); break;
	}

	for (; sortFirst != end; sortFirst+=2, sortSecond+=2) {
		if ((*sortFirst)->value > (*sortSecond)->value) {

			(*sortFirst)->lower.push_back((*sortSecond));
			(*sortSecond)->higher = *sortFirst;
			greaterSequence.push_back(*sortFirst);

			std::iter_swap(sortFirst, sortSecond);
		}
		else {

			(*sortSecond)->lower.push_back((*sortFirst));
			(*sortFirst)->higher = *sortSecond;
			greaterSequence.push_back(*sortSecond);
		}
	}
}

//void	PmergeMe::binaryInsert(SortDeque& sequence, SortDeque& mainChain) {
//	SortDeque::iterator end = sequence.end();
//	SortDeque::iterator i = sequence.begin();
//	int	middle = mainChain.size() / 2;
//
//	for (; i != end; i++) {
//		if (mainChain[middle] > i->first)
//			middle /= 2;
//		else
//			middle += middle / 2;
//	}
//}

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

/* -------------------------------- OVERLOADS -------------------------------- */

bool	ValueData::operator==(ValueData const &rhs) {
	if (this->value == rhs.value)
		return (true);
	return (false);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
