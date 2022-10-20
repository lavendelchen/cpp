/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 20:32:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
ShrubberyCreationForm::ShrubberyCreationForm():
name("Form"), signGrade(Bureaucrat::lowestGrade), exeGrade(Bureaucrat::lowestGrade) {
	this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, bool isSigned, int signGrade, int exeGrade):
name(name), signGrade(signGrade), exeGrade(exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = isSigned;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig):
name(orig.name), signGrade(orig.signGrade), exeGrade(orig.exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = orig.isSigned;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ShrubberyCreationForm::~ShrubberyCreationForm() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	ShrubberyCreationForm::printAttributes(std::ostream &out) const {
	out	<< "NAME: " << this->name;
	if (this->isSigned == false)
		out << "\nShrubberyCreationForm is NOT signed";
	else
		out << "\nShrubberyCreationForm IS signed";
	out	<< "\nGRADES:"
		<< "\nSign Grade: " << this->signGrade
		<< "\nExecution Grade: " << this->exeGrade;
}

const std::string&	ShrubberyCreationForm::getName(void) const {
	return (this->name);
}

bool	ShrubberyCreationForm::getSignStatus(void) const {
	return (this->isSigned);
}

int	ShrubberyCreationForm::getSignGrade(void) const {
	return (this->signGrade);
}

int	ShrubberyCreationForm::getExeGrade(void) const {
	return (this->exeGrade);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw(GradeTooLowException());
	this->isSigned = true;
}

/* --------------------------------- EXCEPTION METHODS --------------------------------- */
const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high 👆");
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low 👇");
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& form) {
	form.printAttributes(out);
	return (out);
}
