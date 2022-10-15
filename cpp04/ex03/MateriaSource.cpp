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
	for (int i = 0; i < this->memorySize; i++) {
		memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &orig) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < this->memorySize; i++) {
		orig.memory[i] == NULL ? this->memory[i] = NULL :
		this->memory[i] = orig.memory[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < this->memorySize; i++) {
			delete this->memory[i];
			rhs.memory[i] == NULL ? this->memory[i] = NULL :
			this->memory[i] = rhs.memory[i]->clone();
		}
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->memorySize; i++) {
		delete memory[i];
	}
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	MateriaSource::printAttributes(std::ostream &out) {
	out << "\nMemory:\n";
	for (int i = 0; i < this->memorySize; i++) {
		out << "Slot " << i << ": ";
		memory[i] == NULL ? out << "[empty]\n" :
		out << *memory[i] << '\n';
	}
}

void		MateriaSource::learnMateria(AMateria* src) {
	for (int i = 0; i < this->memorySize; i++) {
		if (this->memory[i] == NULL) {
			memory[i] = src;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < this->memorySize; i++) {
		if (this->memory[i] != NULL && this->memory[i]->getType() == type) {
			return (memory[i]->clone());
		}
	}
	return (NULL);
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, MateriaSource &memorySource) {
	memorySource.printAttributes(out);
	return (out);
}
