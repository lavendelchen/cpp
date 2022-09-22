/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:41 by shaas             #+#    #+#             */
/*   Updated: 2022/09/22 23:28:42 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "PhoneBook.hpp"

static std::string getContactInfo(const std::string &prompt) {
	std::string	infoStorage;

	while (!std::cin.eof()) {
		std::cout << prompt;
		getline(std::cin, infoStorage);
		if (infoStorage != "")
			return (infoStorage);
		std::cout << "Error: Field can't be empty\n";
	}
	return (infoStorage);
}

void PhoneBook::addContact(void) {
	std::cout << "\nNEW CONTACT\n";
	_contacts[_newContactPlace].setFirstName(getContactInfo("First Name: "));
	_contacts[_newContactPlace].setLastName(getContactInfo("Last Name: "));
	_contacts[_newContactPlace].setNickname(getContactInfo("Nickname: "));
	_contacts[_newContactPlace].setPhoneNumber(getContactInfo("Phone Number: "));
	_contacts[_newContactPlace].setDarkestSecret(getContactInfo("Darkest Secret: "));
	std::cout << "CONTACT SAVED!\n";
	if (_numOfContacts < 8)
		_numOfContacts++;
	_newContactPlace++;
	if (_newContactPlace == 8)
		_newContactPlace = 0;
}

static void printColumn(const std::string &string, char separator)
{
	if (string.size() <= 10)
		std::cout << std::setw(10) << string;
	else
		std::cout << string.substr(0, 9) << '.';
	std::cout << separator;
}

void PhoneBook::printAllContacts(void)
{
	for (short i = 0; i < 8; i++) {
		if (_contacts[i].getFirstName() == "")
			break ;
		std::cout << std::setw(10) << i + 1 << '|';
		printColumn(_contacts[i].getFirstName(), '|');
		printColumn(_contacts[i].getLastName(), '|');
		printColumn(_contacts[i].getNickname(), '\n');
	}
	std::cout << std::endl;
}

bool isNum(std::string &str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void PhoneBook::printContactInfo(int index) {
	std::cout << "First Name: " << _contacts[index].getFirstName();
	std::cout << "\nLast Name: " << _contacts[index].getLastName();
	std::cout << "\nNickname: " << _contacts[index].getNickname();
	std::cout << "\nPhone number: " << _contacts[index].getPhoneNumber();
	std::cout << "\nDarkest secret: " << _contacts[index].getDarkestSecret();
	std::cout << std::endl;
}

void PhoneBook::searchContact(void) {
	if (_numOfContacts == 0) {
		std::cout << "Error: No contacts added yet\n";
		return ;
	}
	printAllContacts();

	std::string index_str;
	int			index;
	while (!std::cin.eof()) {
		std::cout << "\nPlease enter the index of a contact to view contact information: ";
		getline(std::cin, index_str);
		if (isNum(index_str)) {
			index = atoi(index_str.c_str());
			if (index <= _numOfContacts && index > 0)
				return (printContactInfo(index - 1));
		}
		std::cout << "Error: Please enter a valid index\n";
	}
}