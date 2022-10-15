/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:02:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++) {
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(std::string name) {
	std::cout << "MateriaSource name constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < this->inventorySize; i++) {
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &orig) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	this->name = orig.name;
	for (int i = 0; i < this->inventorySize; i++) {
		orig.inventory[i] == NULL ? this->inventory[i] = NULL :
		this->inventory[i] = orig.inventory[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
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
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->inventorySize; i++) {
		delete inventory[i];
	}
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	MateriaSource::printAttributes(std::ostream &out) {
	out << this->name << "\nInventory:\n";
	for (int i = 0; i < this->inventorySize; i++) {
		out << "Slot " << i << ": ";
		inventory[i] == NULL ? out << "[empty]\n" :
		out << *inventory[i] << '\n';
	}
}

void		printAttributes(std::ostream &out);
void		learnMateria(AMateria*);
AMateria*	createMateria(const std::string& type);

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, MateriaSource &materiaSource) {
	materiaSource.printAttributes(out);
	return (out);
}
