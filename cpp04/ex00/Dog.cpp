/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/23 01:00:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

Dog::Dog(std::string name) {
	std::cout << "Dog name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

Dog::Dog(const Dog &orig): ClapTrap(orig) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void Dog::highFivesGuys(void) {
	std::cout << "Dog " << this->name << " wants a high five :)" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Dog &Dog) {
	Dog.printAttributes(out);
	return (out);
}
