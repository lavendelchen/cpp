/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 18:02:49 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &orig) {
	std::cout << "Copy constructor called" << std::endl;
	this->name = orig.name;
	this->hitPoints = orig.hitPoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "ClapTrap " << this->name << " attacks " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else {
		std::cout	<< "ClapTrap " << this->name
					<< " doesn't have enough energy and hit points left to attack."
					<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout	<< "ClapTrap " << this->name << " takes "
				<< amount << " damage!" << std::endl;
	if ((this->hitPoints - (int)amount) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints-=amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "ClapTrap " << this->name << " repairs itself, regaining "
					<< amount << " hit points!" << std::endl;
		this->hitPoints+=amount;
		this->energyPoints--;
	}
	else {
		std::cout	<< "ClapTrap " << this->name
					<< " doesn't have enough energy and hit points left to repair itself."
					<< std::endl;
	}
}

void	ClapTrap::printAttributes(std::ostream &out) {
	out << "Name: " << this->name
		<< "\nHit Points: " << this->hitPoints
		<< "\nEnergy Points: " << this->energyPoints
		<< "\nAttack Damage: " << this->attackDamage
		<< std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, ClapTrap &clapTrap) {
	clapTrap.printAttributes(out);
	return (out);
}
