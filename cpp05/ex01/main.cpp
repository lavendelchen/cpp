/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/19 18:54:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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

	int	signGrade = 100;
	std::cout << "\n-- signForm test (signGrade is modifiable) -- \n";
	Form		f("Form", false, 75, 75);
	Bureaucrat	b("Some Guy", signGrade);
	b.signForm(f);
}
