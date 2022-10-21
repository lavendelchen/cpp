/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 01:58:06 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("Robotomy Request", 72, 45), target(target) { }

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
	std::cout << "*bzzzzzzzz* *brrrrrrrrr* *wruuuuuuummmm*\n";
	std::srand(time(NULL));
	int	isSuccess = std::rand() % 2;
	if (isSuccess)
		std::cout << this->target << " has been successfully robotomized\n";
	else
		std::cout << "Robotomy has failed\n";
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, RobotomyRequestForm& form) {
	form.printAttributes(out);
	return (out);
}
