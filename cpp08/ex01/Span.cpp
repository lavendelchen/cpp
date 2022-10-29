/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 06:22:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Span::Span(): maxElements(0) {
	this->elements.reserve(this->maxElements);
}

Span::Span(unsigned int n): maxElements(n) {
	this->elements.reserve(this->maxElements);
}

Span::Span(const Span &orig): maxElements(orig.maxElements), elements(orig.elements) { }

Span&	Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->maxElements = rhs.maxElements;
		this->elements = rhs.elements;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Span::~Span() { }

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	Span::addNumber(int num) {
	if (this->elements.size() >= this->maxElements)
		throw SpanOverflowException();
	this->elements.push_back(num);
}

void	Span::addRangeOfNumbers(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) {
	while (start < end) {
		if (this->elements.size() >= this->maxElements)
			throw SpanOverflowException();
		this->elements.push_back(*start);
		start++;
	}
}

int	Span::shortestSpan(void) {
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

int	Span::longestSpan(void) const {
	if (this->maxElements <= 1)
		throw TooFewNumbersException();

	int max = *std::max_element(this->elements.begin(), this->elements.end());
	int min = *std::min_element(this->elements.begin(), this->elements.end());
	return (max - min);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
const char* Span::SpanOverflowException::what() const throw() {
	return "Error: Span is already full";
}

const char* Span::TooFewNumbersException::what() const throw() {
	return "Error: Not enough numbers to find span";
}
