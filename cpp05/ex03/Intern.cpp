/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 03:21:46 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* --------------------------------- STATIC CONST VARIABLES --------------------------------- */

const std::string Intern::formName[] = {
	"Shrubbery Creation",
	"Robotomy Request",
	"Presidential Pardon"
};

/* ------------------------------- CONSTRUCTOR --------------------------------*/
Intern::Intern() { }

Intern::Intern(const Intern &orig) { (void)orig; }

Intern&	Intern::operator=(Intern const &rhs) { (void)rhs; return *this; }

/* -------------------------------- DESTRUCTOR -------------------------------- */
Intern::~Intern() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
AForm* Intern::makeForm(std::string formName, std::string formTarget) const {
	static AForm* (*formCreator[])(std::string target) = {
		&ShrubberyCreationForm::createNew,
		&RobotomyRequestForm::createNew,
		&PresidentialPardonForm::createNew,
		NULL
	};

	for (int i = 0; formCreator[i] != NULL; i++) {
		if (formName == Intern::formName[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (formCreator[i](formTarget));
		}
	}
	std::cout << formName << " not created, doesn't exist" << std::endl;
	return (NULL);
}

/* --------------------------------- OVERLOAD --------------------------------- */
