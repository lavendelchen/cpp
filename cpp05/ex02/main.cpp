/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 21:03:00 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

void	shrubberyCreationFormTests(void) {
	std::cout << "\n\033[32mSHRUBBERY CREATION FORM\n";
	// constructor & overload tests
	ShrubberyCreationForm	maple;
	ShrubberyCreationForm	birch(true);
	ShrubberyCreationForm	oak(birch);

	std::cout << "-- Default constructor test -- \n" << maple << "\n\n";
	std::cout << "-- Attribute constructor test -- \n" << birch << "\n\n";
	std::cout << "-- Copy constructor test -- \n" << oak << "\n\n";

	maple = oak;

	std::cout << "-- Copy assignment operator test -- \n" << maple << "\n\n";
}

int main(void) {
	shrubberyCreationFormTests();
	// constructor & overload tests
	// ShrubberyCreationForm	maple;
	// ShrubberyCreationForm	birch(true);
	// ShrubberyCreationForm	oak(birch);

	// std::cout << "-- Default constructor test -- \n" << maple << "\n\n";
	// std::cout << "-- Attribute constructor test -- \n" << birch << "\n\n";
	// std::cout << "-- Copy constructor test -- \n" << oak << "\n\n";

	// maple = oak;

	// std::cout << "-- Copy assignment operator test -- \n" << maple << "\n\n";

	// getter tests
	// std::cout << "-- getName test -- " << birch.getName() << '\n';
	// std::cout << "-- getSignStatus test -- " << birch.getSignStatus() << '\n';
	// std::cout << "-- getSignGrade test -- " << birch.getSignGrade() << '\n';
	// std::cout << "-- getExeGrade test -- " << birch.getExeGrade() << '\n';

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
