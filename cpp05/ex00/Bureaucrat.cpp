/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/17 18:31:37 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Bureaucrat::Bureaucrat(): name("Bureaucrat"), grade(this->highestGrade) { }

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	if (grade < this->highestGrade || grade > this->lowestGrade)
		this->grade = this->highestGrade;
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig): name(orig.name), grade(orig.grade) { }

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->grade = rhs.grade;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Bureaucrat::~Bureaucrat() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Bureaucrat::printAttributes(std::ostream &out) {
	out	<< "Name: " << this->name 
		<< ", Grade: " << this->grade;
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Bureaucrat &character) {
	character.printAttributes(out);
	return (out);
}
