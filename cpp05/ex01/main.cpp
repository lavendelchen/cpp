/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/19 18:38:50 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

int main(void) {
	// constructor & overload tests
	Form	red;
	Form	blue("Blue Form", true, 37, 102);
	Form	green(blue);

	std::cout << "-- Default constructor test -- \n" << red << '\n';
	std::cout << "-- Attribute constructor test -- \n" << blue << '\n';
	std::cout << "-- Copy constructor test -- \n" << green << '\n';

	red = green;

	std::cout << "-- Copy assignment operator test -- \n" << red << '\n';

	// getter tests
	std::cout << "\n-- getName test -- " << blue.getName() << '\n';
	std::cout << "-- getSignStatus test -- " << blue.getSignStatus() << '\n';
	std::cout << "-- getSignGrade test -- " << blue.getSignGrade() << '\n';
	std::cout << "-- getExeGrade test -- " << blue.getExeGrade() << '\n';

	//exception tests
	try {
		int	wrongSignGrade = -40;
		int	wrongExeGrade = 1000;
		std::cout << "\n-- Attribute constructor exception test (wrongGrades are modifiable) -- \n";
		Form	wrong("Wrong", false, wrongSignGrade, wrongExeGrade);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		int	wrongSignGrade = 100;
		std::cout << "\n-- beSigned exception test (wrongSignGrade is modifiable) -- \n";
		Form		f("Form", false, 75, 75);
		Bureaucrat	b("Some Guy", wrongSignGrade);
		f.beSigned(b);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	// try {
		// std::cout << "\n-- Default increase exception test -- \n";
		// Form	creed("Creed", 2);
		// std::cout << creed << '\n';
		// creed.incGrade();
		// std::cout << creed << '\n';
		// creed.incGrade();
		// std::cout << creed << '\n';
	// }
	// catch (std::exception& e) {
		// std::cout << e.what() << '\n';
	// }
	// try {
		// std::cout << "\n-- Default decrease exception test -- \n";
		// Form	meredith("Meredith", 149);
		// std::cout << meredith << '\n';
		// meredith.decGrade();
		// std::cout << meredith << '\n';
		// meredith.decGrade();
		// std::cout << meredith << '\n';
	// }
	// catch (std::exception& e) {
		// std::cout << e.what() << '\n';
	// }

	// int	amount = 200;
	// try {
		// std::cout << "\n-- Amount decrease & increase exception test (amount is modifiable & decGrade or incGrade can be used) -- \n";
		// Form	ryan("Ryan", 75);
		// ryan.decGrade(amount);
		// ryan.incGrade(amount);
	// }
	// catch (std::exception& e) {
		// std::cout << e.what() << '\n';
	// }
}
