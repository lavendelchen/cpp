/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2023/06/21 19:09:38 by shaas            ###   ########.fr       */
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

/* -------------------------------- DESTRUCTOR -------------------------------- */

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
