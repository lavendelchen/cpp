/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/10 14:27:08 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog &orig): Animal(orig) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*(orig.brain));
}

Dog&	Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Dog::printAttributes(std::ostream &out) {
	this->Animal::printAttributes(out);
	this->brain->printAttributes(out);
}

void	Dog::makeSound() const {
	std::cout << "Wuff! 🐶\n";
}

void	Dog::addIdea(std::string idea) {
	this->brain->addIdea(idea);
}

const std::string&	Dog::getIdea(unsigned int index) {
	return (this->brain->getIdea(index));
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Dog &dog) {
	dog.printAttributes(out);
	return (out);
}
