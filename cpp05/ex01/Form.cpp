/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/18 23:16:22 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Form::Form(): name("Form"), grade(this->highestGrade) { }

Form::Form(std::string name, int grade): name(name) {
	if (grade < this->highestGrade)
		throw (GradeTooHighException());
	if (grade > this->lowestGrade)
		throw (GradeTooLowException());
	this->grade = grade;
}

Form::Form(const Form &orig): name(orig.name) {
	if (orig.grade < this->highestGrade)
		throw (GradeTooHighException());
	if (orig.grade > this->lowestGrade)
		throw (GradeTooLowException());
	this->grade = orig.grade;
}

Form&	Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		if (rhs.grade < this->highestGrade)
			throw (GradeTooHighException());
		if (rhs.grade > this->lowestGrade)
			throw (GradeTooLowException());
		this->grade = rhs.grade;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Form::~Form() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */

void	Form::printAttributes(std::ostream &out) {
	out	<< "Name: " << this->name 
		<< ", Grade: " << this->grade;
}

const std::string&	Form::getName(void) const {
	return (this->name);
}

int	Form::getGrade(void) const {
	return (this->grade);
}

void	Form::incGrade(void) {
	if (this->grade == this->highestGrade)
		throw (GradeTooHighException());
	this->grade--;
}

void	Form::decGrade(void) {
	if (this->grade == this->lowestGrade)
		throw (GradeTooLowException());
	this->grade++;
}

void	Form::incGrade(const int amount) {
	if (this->grade - amount < this->highestGrade)
		throw(GradeTooHighException());
	this->grade -= amount;
}
void	Form::decGrade(const int amount) {
	if (this->grade + amount > this->lowestGrade)
		throw(GradeTooLowException());
	this->grade += amount;
}

/* --------------------------------- EXCEPTION METHODS --------------------------------- */
const char* Form::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high 👆");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low 👇");
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream &out, Form &form) {
	form.printAttributes(out);
	return (out);
}
