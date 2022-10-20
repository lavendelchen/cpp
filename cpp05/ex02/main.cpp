/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 22:41:15 by shaas            ###   ########.fr       */
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
	ShrubberyCreationForm	garden("Garden");
	ShrubberyCreationForm	lake(garden);

	std::cout << "-- Default constructor test -- \n" << street << "\n\n";
	std::cout << "-- Attribute constructor test -- \n" << garden << "\n\n";
	std::cout << "-- Copy constructor test -- \n" << lake << "\n\n";

	street = lake;

	std::cout << "-- Copy assignment operator test -- \n" << street << "\n\n";
}

int main(void) {
	shrubberyCreationFormTests();
	// constructor & overload tests
	// ShrubberyCreationForm	street;
	// ShrubberyCreationForm	garden(true);
	// ShrubberyCreationForm	lake(garden);

	// std::cout << "-- Default constructor test -- \n" << street << "\n\n";
	// std::cout << "-- Attribute constructor test -- \n" << garden << "\n\n";
	// std::cout << "-- Copy constructor test -- \n" << lake << "\n\n";

	// street = lake;

	// std::cout << "-- Copy assignment operator test -- \n" << street << "\n\n";

	// getter tests
	// std::cout << "-- getName test -- " << garden.getName() << '\n';
	// std::cout << "-- getSignStatus test -- " << garden.getSignStatus() << '\n';
	// std::cout << "-- getSignGrade test -- " << garden.getSignGrade() << '\n';
	// std::cout << "-- getExeGrade test -- " << garden.getExeGrade() << '\n';

	//exception tests
	// try {
	// 	int	wrongSignGrade = -40;
	// 	int	wrongExeGrade = 1000;
	// 	std::cout << "\n-- Attribute constructor exception test (wrongGrades are modifiable) -- \n";
	// 	ShrubberyCreationForm	wrong("Wrong", false, wrongSignGrade, wrongExeGrade);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << '\n';
	// }

	// int	signGrade = 100;
	// std::cout << "\n-- signShrubberyCreationForm test (signGrade is modifiable) -- \n";
	// ShrubberyCreationForm		f("A Very Important ShrubberyCreationForm", false, 75, 75);
	// Bureaucrat	b("Some Guy", signGrade);
	// b.signShrubberyCreationForm(f);
	// std::cout << f << '\n';
}
