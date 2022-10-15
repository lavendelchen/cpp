/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:02:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Ice::Ice(): AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &orig): AMateria(orig) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice&	Ice::operator=(Ice const &rhs) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

//void	Ice::use(ICharacter& target) {
//	"* shoots an ice bolt at " << target.name << " *" << std::endl;
//}

void	Ice::printAttributes(std::ostream &out) {
	this->AMateria::printAttributes(out);
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Ice &ice) {
	ice.printAttributes(out);
	return (out);
}
