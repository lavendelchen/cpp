/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:25:31 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "idk";
}

WrongAnimal::WrongAnimal(const WrongAnimal &orig) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = orig.type;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	WrongAnimal::printAttributes(std::ostream &out) {
	out << this->type;
}

const std::string	WrongAnimal::getType(void) {
	return (this->type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "...\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, WrongAnimal &wrongAnimal) {
	wrongAnimal.printAttributes(out);
	return (out);
}
