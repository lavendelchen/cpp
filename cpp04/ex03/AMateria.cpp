/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:39:09 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:00:01 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

AMateria::AMateria() {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) {
	std::cout << "AMateria type constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &orig) {
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = orig.type;
}

AMateria&	AMateria::operator=(AMateria const &rhs) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
const std::string& AMateria::getType() const {
	return (this->type);
}

//virtual void AMateria::use(ICharacter& target) {
//	std::cout << "* how would this ever affect " << target.name << "? *" << std::endl;
//}

void	AMateria::printAttributes(std::ostream &out) {
	out << this->type;
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, AMateria &aMateria) {
	aMateria.printAttributes(out);
	return (out);
}