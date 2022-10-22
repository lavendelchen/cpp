/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/22 01:58:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Form::Form():
name("Form"), signGrade(Bureaucrat::lowestGrade), exeGrade(Bureaucrat::lowestGrade) {
	this->isSigned = false;
}

Form::Form(std::string name, int signGrade, int exeGrade):
name(name), signGrade(signGrade), exeGrade(exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = false;
}

Form::Form(const Form &orig):
name(orig.name), signGrade(orig.signGrade), exeGrade(orig.exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = orig.isSigned;
}

Form&	Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
Form::~Form() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	Form::printAttributes(std::ostream &out) const {
	out	<< "NAME: " << this->name;
	if (this->isSigned == false)
		out << "\nForm is NOT signed";
	else
		out << "\nForm IS signed";
	out	<< "\nGRADES:"
		<< "\nSign Grade: " << this->signGrade
		<< "\nExecution Grade: " << this->exeGrade;
}

const std::string&	Form::getName(void) const {
	return (this->name);
}

bool	Form::getSignStatus(void) const {
	return (this->isSigned);
}

int	Form::getSignGrade(void) const {
	return (this->signGrade);
}

int	Form::getExeGrade(void) const {
	return (this->exeGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw(GradeTooLowException());
	this->isSigned = true;
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
