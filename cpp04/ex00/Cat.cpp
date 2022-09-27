/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/23 01:01:07 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

Cat::Cat(std::string name) {
	std::cout << "Cat name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

Cat::Cat(const Cat &orig): ClapTrap(orig) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void Cat::guardGate() {
	std::cout << "Cat " << this->name << " is now in gatekeeper mode!" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Cat &Cat) {
	Cat.printAttributes(out);
	return (out);
}
