/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/19 17:34:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Bureaucrat::Bureaucrat(): name("Bureaucrat"), grade(this->highestGrade) { }

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	if (grade < this->highestGrade)
		throw (GradeTooHighException());
	else if (grade > this->lowestGrade)
		throw (GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig): name(orig.name) {
	if (orig.grade < this->highestGrade)
		throw (GradeTooHighException());
	else if (orig.grade > this->lowestGrade)
		throw (GradeTooLowException());
	this->grade = orig.grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		if (rhs.grade < this->highestGrade)
			throw (GradeTooHighException());
		else if (rhs.grade > this->lowestGrade)
			throw (GradeTooLowException());
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

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void	Bureaucrat::incGrade(void) {
	if (this->grade == this->highestGrade)
		throw (GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decGrade(void) {
	if (this->grade == this->lowestGrade)
		throw (GradeTooLowException());
	this->grade++;
}

void	Bureaucrat::incGrade(const int amount) {
	if (this->grade - amount < this->highestGrade)
		throw(GradeTooHighException());
	this->grade -= amount;
}
void	Bureaucrat::decGrade(const int amount) {
	if (this->grade + amount > this->lowestGrade)
		throw(GradeTooLowException());
	this->grade += amount;
}

/* --------------------------------- EXCEPTION METHODS --------------------------------- */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high 👆");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low 👇");
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
	bureaucrat.printAttributes(out);
	return (out);
}
