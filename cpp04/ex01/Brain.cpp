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
}

Brain::Brain(const Brain &orig) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < this->ideaNum; i++) {
		this->ideas[i] = orig.ideas[i];
	}
}

Brain&	Brain::operator=(Brain const &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < this->ideaNum; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Brain::printAttributes(std::ostream &out) {
	for (int i = 0; i < this->ideaNum; i++) {
		if (!this->ideas[i].empty()) 
			out << "Idea " << i + 1 << ": " << this->ideas[i] << '\n';
	}
}

/* --------------------------------- OVERLOAD --------------------------------- */

std::ostream&	operator<<(std::ostream &out, Brain &brain) {
	brain.printAttributes(out);
	return (out);
}
