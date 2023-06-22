/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2023/06/22 21:46:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ValueData.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

ValueData_deque::ValueData_deque() { }
ValueData_vector::ValueData_vector() { }

ValueData_deque::ValueData_deque(ValueData_deque* lower) {
	this->value = -1;
	this->lower.push_back(lower);
}
ValueData_vector::ValueData_vector(ValueData_vector* lower) {
	this->value = -1;
	this->lower.push_back(lower);
}

ValueData_deque::ValueData_deque(const ValueData_deque &orig):
								value(orig.value), lower(orig.lower) { }

ValueData_vector::ValueData_vector(const ValueData_vector &orig):
								value(orig.value), lower(orig.lower) { }

ValueData_deque&	ValueData_deque::operator=(const ValueData_deque &rhs) {
	if (this != &rhs) {
		this->value = rhs.value;
		this->lower = rhs.lower;
	}
	return *this;
}

ValueData_vector&	ValueData_vector::operator=(const ValueData_vector &rhs) {
	if (this != &rhs) {
		this->value = rhs.value;
		this->lower = rhs.lower;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ValueData_deque::~ValueData_deque() { }

ValueData_vector::~ValueData_vector() { }

/* -------------------------------- PRIVATE METHODS -------------------------------- */

/* -------------------------------- PUBLIC METHODS -------------------------------- */

ValueData_deque*	ValueData_deque::getNewestLower(void) {
	if (this->lower.empty())
		return (NULL);

	ValueData_deque* newestLower = this->lower.back();
	this->lower.pop_back();
	return (newestLower);
}
ValueData_vector*	ValueData_vector::getNewestLower(void) {
	if (this->lower.empty())
		return (NULL);

	ValueData_vector* newestLower = this->lower.back();
	this->lower.pop_back();
	return (newestLower);
}

/* -------------------------------- OVERLOADS -------------------------------- */

bool	ValueData_deque::operator==(ValueData_deque const &rhs) {
	if (this->value == rhs.value)
		return (true);
	return (false);
}
bool	ValueData_vector::operator==(ValueData_vector const &rhs) {
	if (this->value == rhs.value)
		return (true);
	return (false);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
