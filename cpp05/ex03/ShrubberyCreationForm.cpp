/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/22 02:07:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation", 145, 137), target("Unknown target") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("Shrubbery Creation", 145, 137), target(target) { }

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

	std::ofstream	targetFile((this->target + "_shrubbery").c_str());
	targetFile	<< "               ,@@@@@@@,                 \n"
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.     \n"
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    \n"
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   \n"
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   \n"
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    \n"
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'      \n"
				<< "       |o|        | |         | |        \n"
				<< "       |.|        | |         | |        \n"
				<< "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	targetFile.close();
}

AForm*	ShrubberyCreationForm::createNew(std::string target) {
	return (new ShrubberyCreationForm(target));
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& form) {
	form.printAttributes(out);
	return (out);
}
