/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 23:14:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
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

	int	bGrade = 146;
	std::cout << "-- executeForm test (bGrade is modifiable) -- \n";
	ShrubberyCreationForm	f("home");
	Bureaucrat	b("Some Guy", bGrade);
	b.signForm(f);
	b.executeForm(f);
	// show result of form execution!
}

int main(void) {
	shrubberyCreationFormTests();
}
