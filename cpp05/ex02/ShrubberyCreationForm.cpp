/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 22:34:56 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", 145, 137), target("?") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("Shrubbery Creation Form", 145, 137), target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig):
	AForm(orig), target(orig.target) { }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
ShrubberyCreationForm::~ShrubberyCreationForm() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	ShrubberyCreationForm::printAttributes(std::ostream &out) const {
	this->AForm::printAttributes(out);
	out << "\nTarget: " << this->target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->canBeExecuted(executor);
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& form) {
	form.printAttributes(out);
	return (out);
}
