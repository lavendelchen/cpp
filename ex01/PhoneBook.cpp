/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:41 by shaas             #+#    #+#             */
/*   Updated: 2022/07/06 21:18:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

#include "PhoneBook.hpp"

static void getContactInfo(const std::string &prompt, std::string &infoStorage) {
	while (!std::cin.eof()) {
		std::cout << prompt;
		getline(std::cin, infoStorage);
		if (infoStorage != "")
			return ;
		std::cout << "Error: Field can't be empty\n";
	}
}

void PhoneBook::addContact(void) {
	std::cout << "\nNEW CONTACT\n";
	getContactInfo("First Name: ", _contacts[_newContactPlace].firstName);
	getContactInfo("Last Name: ", _contacts[_newContactPlace].lastName);
	getContactInfo("Nickname: ", _contacts[_newContactPlace].nickname);
	getContactInfo("Phone number: ", _contacts[_newContactPlace].phoneNumber);
	getContactInfo("Darkest secret: ", _contacts[_newContactPlace].darkestSecret);
	std::cout << "CONTACT SAVED!\n\n";
	if (_numOfContacts < 8)
		_numOfContacts++;
	_newContactPlace++;
	if (_newContactPlace == 8)
		_newContactPlace = 0;
}

static void printColumn(std::string &string, char separator)
{
	if (string.size() <= 10)
		std::cout << std::setw(10) << string;
	else
		std::cout << string.substr(0, 9) << '.';
	std::cout << separator;
}

void PhoneBook::printContacts(void)
{
	for (short i = 0; i < 8; i++) {
		if (_contacts[i].firstName == "") //o-ooh
			break ;
		std::cout << std::setw(10) << i + 1 << '|'; // remember to subtract in search
		printColumn(_contacts[i].firstName, '|');
		printColumn(_contacts[i].lastName, '|');
		printColumn(_contacts[i].nickname, '\n');
	}
	std::cout << std::endl;
}

bool isNum(std::string &str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void PhoneBook::printContactInfo(int index) {
	
}

void PhoneBook::searchContact(void) {
	printContacts();

	std::string index_str;
	int			index;

	while (!std::cin.eof()) {
		std::cout << "Please enter the index of a contact to view contact information: ";
		getline(std::cin, index_str);
		if (isNum(index_str)) {
			index = atoi(index_str.c_str());
			if (index <= _numOfContacts)
				return (printContactInfo(index - 1));
		}
		std::cout << "Error: Please enter a valid index\n";
	}
}