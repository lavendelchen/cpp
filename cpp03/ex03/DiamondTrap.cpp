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

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->hitPoints = this->FragTrap::hitPoints;
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = this->FragTrap::hitPoints;
	this->energyPoints = this->ScavTrap::energyPoints;
	this->attackDamage = this->FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig):  ClapTrap(orig), ScavTrap(orig), FragTrap(orig) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = orig.name;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
		this->ClapTrap::name = rhs.ClapTrap::name;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout	<< "My name is " << this->name
				<< " and my ClapTrap name is " << this->ClapTrap::name
				<< std::endl;
}

void	DiamondTrap::printAttributes(std::ostream &out) {
	out << "\nName: " << this->name
		<< "\nClapTrap Name: " << this->ClapTrap::name
		<< "\nHit Points: " << this->hitPoints
		<< "\nEnergy Points: " << this->energyPoints
		<< "\nAttack Damage: " << this->attackDamage
		<< "\n" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, DiamondTrap &diamondTrap) {
	diamondTrap.printAttributes(out);
	return (out);
}
