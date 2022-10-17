/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/17 16:43:30 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main(void) {
	Bureaucrat	oscar;
	Bureaucrat	angela("Angela", 34);
	Bureaucrat	kevin(angela);
	Bureaucrat	wrong("Wrong", -40);
	Bureaucrat	wrong2("Wrong2", 1000);

	std::cout << oscar << '\n';
	std::cout << angela << '\n';
	std::cout << kevin << '\n';
	std::cout << wrong << '\n';
	std::cout << wrong2 << '\n';

	oscar = kevin;

	std::cout << oscar << '\n';

}
