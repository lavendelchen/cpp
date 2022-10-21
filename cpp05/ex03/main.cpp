/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 03:24:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>
#include <string>

int main(void) {
	Intern	intern;

	AForm*	shrubbery = intern.makeForm("Shrubbery Creation", "a place");
	AForm*	robotomy = intern.makeForm("Robotomy Request", "a human");
	AForm*	pardon = intern.makeForm("Presidential Pardon", "a person");
	AForm*	random = intern.makeForm("mncncn", "the moon");

	std::cout << *shrubbery << "\n\n";
	std::cout << *robotomy << "\n\n";
	std::cout << *pardon << "\n\n";
	std::cout << random << "\n\n";

	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete random;
	return (0);
}
