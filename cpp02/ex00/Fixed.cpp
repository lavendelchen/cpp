/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:53:36 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 00:08:17 by shaas            ###   ########.fr       */
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

/* --------------------------------- PUBLIC FUNCTIONS --------------------------------- */
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member funtion called\n";
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->rawBits = raw;
}
