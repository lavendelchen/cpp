/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:27:42 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

WrongDog::WrongDog() {
	std::cout << "WrongDog default constructor called" << std::endl;
	this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &orig): WrongAnimal(orig) {
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog&	WrongDog::operator=(WrongDog const &rhs) {
	std::cout << "WrongDog copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
WrongDog::~WrongDog() {
	std::cout << "WrongDog destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	WrongDog::makeSound() const {
	std::cout << "Wuff! 🐶\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, WrongDog &wrongDog) {
	wrongDog.printAttributes(out);
	return (out);
}
