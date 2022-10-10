/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:26:43 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &orig): WrongAnimal(orig) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	WrongCat::makeSound() const {
	std::cout << "Meowwww 😺\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, WrongCat &wrongCat) {
	wrongCat.printAttributes(out);
	return (out);
}
