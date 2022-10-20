/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 23:23:12 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
RobotomyRequestForm::RobotomyRequestForm():
	AForm("Shrubbery Creation Form", 145, 137) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("Shrubbery Creation Form", 145, 137), target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig):
	AForm(orig), target(orig.target) { }

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
RobotomyRequestForm::~RobotomyRequestForm() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	RobotomyRequestForm::printAttributes(std::ostream &out) const {
	this->AForm::printAttributes(out);
	out << "\nTarget: " << this->target;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->canBeExecuted(executor);

	std::ofstream	targetFile(this->target + "_shrubbery");
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

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, RobotomyRequestForm& form) {
	form.printAttributes(out);
	return (out);
}
