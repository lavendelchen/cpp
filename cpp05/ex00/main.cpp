/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/18 22:51:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main(void) {
	// constructor & overload tests
	Bureaucrat	oscar;
	Bureaucrat	angela("Angela", 34);
	Bureaucrat	kevin(angela);

	std::cout << "-- Default constructor test -- \n" << oscar << '\n';
	std::cout << "-- Attribute constructor test -- \n" << angela << '\n';
	std::cout << "-- Copy constructor test -- \n" << kevin << '\n';

	oscar = kevin;

	std::cout << "-- Copy assignment operator test -- \n" << oscar << '\n';

	// getter tests

	std::cout << "\n-- getName & getGrade test -- \n" << angela.getName() << angela.getGrade() << '\n';

	// exception tests
	int	wrongGrade = -40;
	try {
		std::cout << "\n-- Attribute constructor exception test (wrongGrade is modifiable) -- \n";
		Bureaucrat	wrong("Wrong", wrongGrade);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		std::cout << "\n-- Default increase exception test -- \n";
		Bureaucrat	creed("Creed", 2);
		std::cout << creed << '\n';
		creed.incGrade();
		std::cout << creed << '\n';
		creed.incGrade();
		std::cout << creed << '\n';
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << "\n-- Default decrease exception test -- \n";
		Bureaucrat	meredith("Meredith", 149);
		std::cout << meredith << '\n';
		meredith.decGrade();
		std::cout << meredith << '\n';
		meredith.decGrade();
		std::cout << meredith << '\n';
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	int	amount = 200;
	try {
		std::cout << "\n-- Amount decrease & increase exception test (amount is modifiable & decGrade or incGrade can be used) -- \n";
		Bureaucrat	ryan("Ryan", 75);
		ryan.decGrade(amount);
		ryan.incGrade(amount);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
}
