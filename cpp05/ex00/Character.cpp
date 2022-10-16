/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:02:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	std::cout << "Character name constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < this->inventorySize; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &orig) {
	std::cout << "Character copy constructor called" << std::endl;
	this->name = orig.name;
	for (int i = 0; i < this->inventorySize; i++) {
		orig.inventory[i] == NULL ? this->inventory[i] = NULL :
		this->inventory[i] = orig.inventory[i]->clone();
	}
}

Character&	Character::operator=(Character const &rhs) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < this->inventorySize; i++) {
			delete this->inventory[i];
			rhs.inventory[i] == NULL ? this->inventory[i] = NULL :
			this->inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++) {
		delete inventory[i];
	}
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Character::printAttributes(std::ostream &out) {
	out << this->name << "\nInventory:\n";
	for (int i = 0; i < this->inventorySize; i++) {
		out << "Slot " << i << ": ";
		inventory[i] == NULL ? out << "[empty]\n" :
		out << *inventory[i] << '\n';
	}
}

void	Character::setName(std::string name) {
	this->name = name;
}

const std::string&	Character::getName() const {
	return (this->name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < this->inventorySize; i++) {
		if (this->inventory[i] == m) {
			std::cout << "Materia already equipped." << std::endl;
			return ;
		}
	}
	for (int i = 0; i < this->inventorySize; i++) {
		if (this->inventory[i] == NULL) {
			inventory[i] = m;
			return ;
		}
	}
}

/* my way of handling the dumbass memory leaks is not having the character
be responsible of them and notifying you with this note. take care of it in
your main function darlin and turn ya brain on 
idea: return the pointer.*/
void	Character::unequip(int idx) {

	if (idx >= this->inventorySize || idx < 0) {
		std::cout << "Requested slot is out of bounds, cannot be unequipped" << std::endl;
		return ;
	}
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= this->inventorySize || idx < 0) {
		std::cout << "Requested slot is out of bounds, cannot be used" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL) {
		inventory[idx]->use(target);
	}
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Character &character) {
	character.printAttributes(out);
	return (out);
}
