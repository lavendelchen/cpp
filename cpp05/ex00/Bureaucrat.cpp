/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 05:24:26 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Bureaucrat::Bureaucrat(): name("Bureaucrat") {
	std::cout << "Bureaucrat default constructor called" << std::endl;
	grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {
	std::cout << "Bureaucrat name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig): name(orig.name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->grade = orig.grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->grade = rhs.grade;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Bureaucrat::printAttributes(std::ostream &out) {
	out	<< "Name: " << this->name 
		<< "Grade: " << this->grade;
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Bureaucrat &character) {
	character.printAttributes(out);
	return (out);
}
