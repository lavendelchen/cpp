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

Character::Character(const Character &orig) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++) {
		inventory[i] = orig.inventory[i];
	}
}

Character&	Character::operator=(Character const &rhs) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < this->inventorySize; i++) {
			inventory[i] = rhs.inventory[i];
		}
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Character::printAttributes(std::ostream &out) {
	out << "Inventory:\n";
	for (int i = 0; i < this->inventorySize; i++) {
		out << "Slot " << i << ": ";
		inventory[i] == NULL ? out << "[empty]\n" :
		out << *inventory[i] << '\n';
	}
}

const std::string&	Character::getName() const {
	return (this->name);
}

/* flaw of this method that i'm too lazy to fix:
1 item can be equipped multiple times, there is no check for that */
void	Character::equip(AMateria* m) {
	for (int i = 0; i < this->inventorySize; i++) {
		if (this->inventory[i] == NULL) {
			inventory[i] = m;
			return ;
		}
	}
}

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
