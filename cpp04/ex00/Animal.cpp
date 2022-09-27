/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 16:17:03 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

Animal::Animal(std::string name) {
	std::cout << "Animal name constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

Animal::Animal(const Animal &orig) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->name = orig.name;
	this->hitPoints = orig.hitPoints;
	this->energyPoints = orig.energyPoints;
	this->attackDamage = orig.attackDamage;
}

Animal&	Animal::operator=(Animal const &rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void Animal::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "Animal " << this->name << " attacks " << target
					<< ", causing " << this->attackDamage
					<< " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else {
		std::cout	<< "Animal " << this->name
					<< " doesn't have enough energy and hit points left to attack."
					<< std::endl;
	}
}

void Animal::takeDamage(unsigned int amount) {
	std::cout	<< "Animal " << this->name << " takes "
				<< amount << " damage!" << std::endl;
	if ((this->hitPoints - (int)amount) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints-=amount;
}

void Animal::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout	<< "Animal " << this->name << " repairs itself, regaining "
					<< amount << " hit points!" << std::endl;
		this->hitPoints+=amount;
		this->energyPoints--;
	}
	else {
		std::cout	<< "Animal " << this->name
					<< " doesn't have enough energy and hit points left to repair itself."
					<< std::endl;
	}
}

void	Animal::printAttributes(std::ostream &out) {
	out << "\nName: " << this->name
		<< "\nHit Points: " << this->hitPoints
		<< "\nEnergy Points: " << this->energyPoints
		<< "\nAttack Damage: " << this->attackDamage
		<< "\n" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Animal &Animal) {
	Animal.printAttributes(out);
	return (out);
}
