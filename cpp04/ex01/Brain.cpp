/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:57:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	index = 0;
}

Brain::Brain(const Brain &orig) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (uint i = 0; i < this->ideaNum; i++) {
		this->ideas[i] = orig.ideas[i];
	}
	this->index = orig.index;
}

Brain&	Brain::operator=(Brain const &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (uint i = 0; i < this->ideaNum; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
		this->index = rhs.index;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Brain::printAttributes(std::ostream &out) {
	for (uint i = 0; i < this->ideaNum; i++) {
		if (!this->ideas[i].empty()) 
			out << "Idea " << i + 1 << ": " << this->ideas[i] << '\n';
	}
}

void	Brain::addIdea(std::string idea) {
	this->ideas[this->index] = idea;
	index++;
	if (this->index >= this->ideaNum)
		index = 0;
}

const std::string&	Brain::getIdea(unsigned int index) {
	return (this->ideas[index]);
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Brain &brain) {
	brain.printAttributes(out);
	return (out);
}
