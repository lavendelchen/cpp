/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:37:01 by shaas             #+#    #+#             */
/*   Updated: 2022/07/09 19:45:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "\nWelcome to my awesome phone book!" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "\nPlease input command: ";
		getline(std::cin, input);
		if (input == "ADD")
			phoneBook.addContact();
		if (input == "SEARCH")
			phoneBook.searchContact();
		if (input == "EXIT")
			return (0);
	}
}