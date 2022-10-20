/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 20:14:48 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
AForm::AForm():
name("Form"), signGrade(Bureaucrat::lowestGrade), exeGrade(Bureaucrat::lowestGrade) {
	this->isSigned = false;
}

AForm::AForm(std::string name, bool isSigned, int signGrade, int exeGrade):
name(name), signGrade(signGrade), exeGrade(exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = isSigned;
}

AForm::AForm(const AForm &orig):
name(orig.name), signGrade(orig.signGrade), exeGrade(orig.exeGrade) {
	if (signGrade < Bureaucrat::highestGrade || exeGrade < Bureaucrat::highestGrade)
		throw (GradeTooHighException());
	else if (signGrade > Bureaucrat::lowestGrade || exeGrade > Bureaucrat::lowestGrade)
		throw (GradeTooLowException());
	this->isSigned = orig.isSigned;
}

AForm&	AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
AForm::~AForm() { }

/* --------------------------------- PROTECTED METHODS --------------------------------- */
void	AForm::canBeExecuted(const Bureaucrat& executor) const {
	if (this->isSigned == false)
		throw (IsNotSignedException());
	else if (executor.getGrade() > this->exeGrade)
		throw(GradeTooLowException());
}

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	AForm::printAttributes(std::ostream &out) const {
	out	<< "NAME: " << this->name;
	if (this->isSigned == false)
		out << "\nForm is NOT signed";
	else
		out << "\nForm IS signed";
	out	<< "\nGRADES:"
		<< "\nSign Grade: " << this->signGrade
		<< "\nExecution Grade: " << this->exeGrade;
}

const std::string&	AForm::getName(void) const {
	return (this->name);
}

bool	AForm::getSignStatus(void) const {
	return (this->isSigned);
}

int	AForm::getSignGrade(void) const {
	return (this->signGrade);
}

int	AForm::getExeGrade(void) const {
	return (this->exeGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw(GradeTooLowException());
	this->isSigned = true;
}

/* --------------------------------- EXCEPTION METHODS --------------------------------- */
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high 👆");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low 👇");
}

const char* AForm::IsNotSignedException::what() const throw() {
	return ("Error: Form not signed 📝");
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, AForm& aform) {
	aform.printAttributes(out);
	return (out);
}
