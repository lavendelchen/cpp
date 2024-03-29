/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 01:40:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

void	shrubberyCreationFormTests(void) {
	std::cout << "\n\033[32mSHRUBBERY CREATION FORM\n";
	// constructor & overload tests
	ShrubberyCreationForm	street;
	ShrubberyCreationForm	garden("garden");
	ShrubberyCreationForm	lake(garden);

	std::cout << "-- Default constructor test -- \n" << street << "\n\n";
	std::cout << "-- Attribute constructor test -- \n" << garden << "\n\n";
	std::cout << "-- Copy constructor test -- \n" << lake << "\n\n";

	street = lake;

	std::cout << "-- Copy assignment operator test -- \n" << street << "\n\n";

	int	bGrade = 130;
	std::cout << "-- executeForm test (bGrade is modifiable) -- \n";
	Bureaucrat	b("The Gardener", bGrade);
	b.signForm(garden);
	b.executeForm(garden);
	// show result of form execution!
}

void	robotomyRequestFormTests(void) {
	std::cout << "\n\033[90mROBOTOMY REQUEST FORM\n";
	// constructor & overload tests
	RobotomyRequestForm	lia;
	RobotomyRequestForm	riley("Riley");
	RobotomyRequestForm	jude(riley);

	std::cout << "-- Default constructor test -- \n" << lia << "\n\n";
	std::cout << "-- Attribute constructor test -- \n" << riley << "\n\n";
	std::cout << "-- Copy constructor test -- \n" << jude << "\n\n";

	lia = jude;

	std::cout << "-- Copy assignment operator test -- \n" << lia << "\n\n";

	int	bGrade = 45;
	std::cout << "-- executeForm test (bGrade is modifiable) -- \n";
	Bureaucrat	b("The Mechanic", bGrade);
	b.signForm(riley);
	b.executeForm(riley);
	// show result of form execution!
}

void	presidentialPardonFormTests(void) {
	std::cout << "\n\033[35mPRESIDENTIAL PARDON FORM\n";
	// constructor & overload tests
	PresidentialPardonForm	toni;
	PresidentialPardonForm	jakob("Jakob");
	PresidentialPardonForm	gio(jakob);

	std::cout << "-- Default constructor test -- \n" << toni << "\n\n";
	std::cout << "-- Attribute constructor test -- \n" << jakob << "\n\n";
	std::cout << "-- Copy constructor test -- \n" << gio << "\n\n";

	toni = gio;

	std::cout << "-- Copy assignment operator test -- \n" << toni << "\n\n";

	int	bGrade = 5;
	std::cout << "-- executeForm test (bGrade is modifiable) -- \n";
	Bureaucrat	b("The Politician", bGrade);
	b.signForm(jakob);
	b.executeForm(jakob);
	// show result of form execution!
}

int main(void) {
	shrubberyCreationFormTests();
	robotomyRequestFormTests();
	presidentialPardonFormTests();
	return (0);
}
