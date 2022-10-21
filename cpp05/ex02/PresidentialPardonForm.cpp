/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 01:58:00 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon", 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("Presidential Pardon", 25, 5), target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig):
	AForm(orig), target(orig.target) { }

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
PresidentialPardonForm::~PresidentialPardonForm() { }

/* --------------------------------- PUBLIC METHODS --------------------------------- */
void	PresidentialPardonForm::printAttributes(std::ostream &out) const {
	this->AForm::printAttributes(out);
	out << "\nTarget: " << this->target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->canBeExecuted(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/* --------------------------------- OVERLOAD --------------------------------- */
std::ostream&	operator<<(std::ostream& out, PresidentialPardonForm& form) {
	form.printAttributes(out);
	return (out);
}
