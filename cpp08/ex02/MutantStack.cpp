/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 17:08:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
MutantStack::MutantStack(): maxElements(0) {
	this->elements.reserve(this->maxElements);
}

MutantStack::MutantStack(unsigned int n): maxElements(n) {
	this->elements.reserve(this->maxElements);
}

MutantStack::MutantStack(const MutantStack &orig): maxElements(orig.maxElements), elements(orig.elements) { }

MutantStack&	MutantStack::operator=(const MutantStack &rhs) {
	if (this != &rhs) {
		this->maxElements = rhs.maxElements;
		this->elements = rhs.elements;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
MutantStack::~MutantStack() { }

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	MutantStack::addNumber(int num) {
	if (this->elements.size() >= this->maxElements)
		throw MutantStackOverflowException();
	this->elements.push_back(num);
}

void	MutantStack::addRangeOfNumbers(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) {
	while (start < end) {
		if (this->elements.size() >= this->maxElements)
			throw MutantStackOverflowException();
		this->elements.push_back(*start);
		start++;
	}
}

int	MutantStack::shortestMutantStack(void) {
	if (this->maxElements <= 1)
		throw TooFewNumbersException();

	std::sort(this->elements.begin(), this->elements.end());

	int shortest = elements[1] - elements[0];
	std::vector<int>::const_iterator iter = elements.begin() + 2;
	while (iter < elements.end()) {
		if (*iter - *(iter - 1) < shortest)
			shortest = *iter - *(iter - 1);
		iter++;
	}
	return shortest;
}

int	MutantStack::longestMutantStack(void) const {
	if (this->maxElements <= 1)
		throw TooFewNumbersException();

	int max = *std::max_element(this->elements.begin(), this->elements.end());
	int min = *std::min_element(this->elements.begin(), this->elements.end());
	return (max - min);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
const char* MutantStack::MutantStackOverflowException::what() const throw() {
	return "Error: MutantStack is already full";
}

const char* MutantStack::TooFewNumbersException::what() const throw() {
	return "Error: Not enough numbers to find span";
}
