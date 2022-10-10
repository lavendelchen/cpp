/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/10 14:46:38 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &orig): Animal(orig) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(orig.brain));
}

Cat&	Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Cat::printAttributes(std::ostream &out) {
	this->Animal::printAttributes(out);
	out << '\n';
	this->brain->printAttributes(out);
}

void	Cat::makeSound() const {
	std::cout << "Meowwww 😺\n";
}

void	Cat::addIdea(std::string idea) {
	this->brain->addIdea(idea);
}

/**
 * @param index 1 is first element, not 0.
 */
const std::string&	Cat::getIdea(unsigned int index) {
	return (this->brain->getIdea(index));
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Cat &cat) {
	cat.printAttributes(out);
	return (out);
}
