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
void	PmergeMe::inputParsing(char* input[], std::deque<int>& sequence) {
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
		if (std::find(sequence.begin(), sequence.end(), buffer) != sequence.end())
			throw std::logic_error("Error: No duplicates please");
		sequence.push_back(buffer);
	}
	for (std::deque<int>::iterator i = sequence.begin(); i != sequence.end(); i++) {
		std::cout << '[' << *i << "] ";
	}
}

void	PmergeMe::mergeMe_deque(char* input[]) {
	std::deque<int>	sequence;

	inputParsing(input, sequence);
}

void	PmergeMe::mergeMe_vector(char* input[]) {
	(void)input;
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
