/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/22 23:59:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &orig): ClapTrap(orig) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, ScavTrap &scavTrap) {
	scavTrap.printAttributes(out);
	return (out);
}
