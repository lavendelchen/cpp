/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 23:27:42 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("Robotomy Request Form", 72, 45), target(target) { }

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
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, RobotomyRequestForm& form) {
	form.printAttributes(out);
	return (out);
}
