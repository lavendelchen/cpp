/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:02:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Cure::Cure(): AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &orig): AMateria(orig) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=(Cure const &rhs) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

void	Cure::printAttributes(std::ostream &out) {
	this->AMateria::printAttributes(out);
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Cure &cure) {
	cure.printAttributes(out);
	return (out);
}
