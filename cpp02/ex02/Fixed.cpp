/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 00:01:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Fixed::Fixed() {
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &orig) {
	this->rawBits = orig.getRawBits();
}

Fixed::Fixed(const int num) {
	std::cout << "hellloooooo this is the int constructor called with " << num << std::endl;
	this->rawBits = num << Fixed::rhsBits;
}

Fixed::Fixed(const float num) {
	this->rawBits = roundf(num * (1 << Fixed::rhsBits));
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Fixed::~Fixed() {
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
int	Fixed::getRawBits() const {
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->rawBits / (float)(1 << Fixed::rhsBits));
}

int		Fixed::toInt(void) const {
	return (this->rawBits >> Fixed::rhsBits);
}

	/*static methods*/

Fixed&	Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1 <= num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1.getRawBits() <= num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1 >= num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1.getRawBits() >= num2.getRawBits())
		return (num1);
	return (num2);
}

/* --------------------------------- OVERLOAD --------------------------------- */
Fixed&	Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs) {
		this->rawBits = rhs.getRawBits();
	}
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs) {
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &rhs) {
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) {
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) {
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) {
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) {
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) {
	Fixed result(this->toFloat() * rhs.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) {
	Fixed result(this->toFloat() / rhs.toFloat());
	return (result);
}

Fixed&	Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (old);
}

Fixed&	Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (old);
}

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}
