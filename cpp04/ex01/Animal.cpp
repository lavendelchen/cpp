/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:57:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "idk";
}

Animal::Animal(const Animal &orig) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = orig.type;
}

Animal&	Animal::operator=(Animal const &rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Animal::printAttributes(std::ostream &out) {
	out << this->type;
}

const std::string	Animal::getType(void) {
	return (this->type);
}

void	Animal::makeSound() const {
	std::cout << "...\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Animal &animal) {
	animal.printAttributes(out);
	return (out);
}
