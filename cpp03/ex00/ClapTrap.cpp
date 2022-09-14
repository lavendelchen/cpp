/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 00:01:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
ClapTrap::ClapTrap() {
	this->rawBits = 0;
}

ClapTrap::ClapTrap(const ClapTrap &orig) {
	this->rawBits = orig.getRawBits();
}

ClapTrap::ClapTrap(const int num) {
	std::cout << "hellloooooo this is the int constructor called with " << num << std::endl;
	this->rawBits = num << ClapTrap::rhsBits;
}

ClapTrap::ClapTrap(const float num) {
	this->rawBits = roundf(num * (1 << ClapTrap::rhsBits));
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ClapTrap::~ClapTrap() {
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
int	ClapTrap::getRawBits() const {
	return (this->rawBits);
}

void	ClapTrap::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	ClapTrap::toFloat(void) const {
	return ((float)this->rawBits / (float)(1 << ClapTrap::rhsBits));
}

int		ClapTrap::toInt(void) const {
	return (this->rawBits >> ClapTrap::rhsBits);
}

	/*static methods*/

ClapTrap&	ClapTrap::min(ClapTrap &num1, ClapTrap &num2) {
	if (num1 <= num2)
		return (num1);
	return (num2);
}

const ClapTrap&	ClapTrap::min(const ClapTrap &num1, const ClapTrap &num2) {
	if (num1.getRawBits() <= num2.getRawBits())
		return (num1);
	return (num2);
}

ClapTrap&	ClapTrap::max(ClapTrap &num1, ClapTrap &num2) {
	if (num1 >= num2)
		return (num1);
	return (num2);
}

const ClapTrap&	ClapTrap::max(const ClapTrap &num1, const ClapTrap &num2) {
	if (num1.getRawBits() >= num2.getRawBits())
		return (num1);
	return (num2);
}

/* --------------------------------- OVERLOAD --------------------------------- */
ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->rawBits = rhs.getRawBits();
	}
	return *this;
}

bool	ClapTrap::operator>(ClapTrap const &rhs) {
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	ClapTrap::operator<(ClapTrap const &rhs) {
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	ClapTrap::operator>=(ClapTrap const &rhs) {
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	ClapTrap::operator<=(ClapTrap const &rhs) {
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	ClapTrap::operator==(ClapTrap const &rhs) {
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	ClapTrap::operator!=(ClapTrap const &rhs) {
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

ClapTrap	ClapTrap::operator+(ClapTrap const &rhs) {
	ClapTrap result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

ClapTrap	ClapTrap::operator-(ClapTrap const &rhs) {
	ClapTrap result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

ClapTrap	ClapTrap::operator*(ClapTrap const &rhs) {
	ClapTrap result(this->toFloat() * rhs.toFloat());
	return (result);
}

ClapTrap	ClapTrap::operator/(ClapTrap const &rhs) {
	ClapTrap result(this->toFloat() / rhs.toFloat());
	return (result);
}

ClapTrap&	ClapTrap::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

ClapTrap	ClapTrap::operator++(int) {
	ClapTrap	old(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (old);
}

ClapTrap&	ClapTrap::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

ClapTrap	ClapTrap::operator--(int) {
	ClapTrap	old(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (old);
}

std::ostream&	operator<<(std::ostream &out, ClapTrap const &ClapTrap) {
	out << ClapTrap.toFloat();
	return (out);
}
