/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 16:44:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	//this->hitPoints = 100;
	//this->energyPoints = 50;
	//this->attackDamage = 20;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap() {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig): ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->hitPoints = orig.hitPoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void DiamondTrap::guardGate() {
	std::cout << "DiamondTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, DiamondTrap &DiamondTrap) {
	DiamondTrap.printAttributes(out);
	return (out);
}
