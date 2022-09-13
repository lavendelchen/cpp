/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 01:05:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &orig) {
	std::cout << "Copy constructor called\n";
	this->rawBits = orig.getRawBits();
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	this->rawBits = num << Fixed::rhsBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	this->rawBits = roundf(num * (1 << Fixed::rhsBits));
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */
Fixed&	Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		this->rawBits = rhs.getRawBits();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}

/* --------------------------------- PUBLIC FUNCTIONS --------------------------------- */
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
