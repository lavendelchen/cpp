/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 21:46:24 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", false, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(bool isSigned): 
	AForm("Shrubbery Creation Form", isSigned, 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig):
	AForm(orig) { }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) { }
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ShrubberyCreationForm::~ShrubberyCreationForm() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	ShrubberyCreationForm::printAttributes(std::ostream &out) const {
	this->AForm::printAttributes(out);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->canBeExecuted(executor);
	
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& form) {
	form.printAttributes(out);
	return (out);
}
