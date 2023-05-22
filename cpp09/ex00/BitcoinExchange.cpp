/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 19:01:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string databaseFile) {
	this->parseDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig): database(orig.database) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->database = rhs.database;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
BitcoinExchange::~BitcoinExchange() { }

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	BitcoinExchange::parseDatabase(std::string &databaseFile) {
	std::ifstream	dataStream(databaseFile.c_str());
	if (!dataStream.is_open()) {
		throw CannotOpenFileException();
	}

	std::string	buffer;
	int			date;
	//float		rate;

	std::getline(dataStream, buffer);
	while (std::getline(dataStream, buffer)) {
		date = dateIntConverter(buffer);
		date = date + 1;
		//this->database.insert(std::pair<std::)
	}
	
}

int		BitcoinExchange::dateIntConverter(std::string dateString) {
	int buffer;
	int	result;
	std::stringstream	dateStream(dateString);

	dateStream >> buffer;
	result = buffer * 10000;

	dateStream.seekg(dateString.find('-')+1);
	dateStream >> buffer;
	result += buffer * 100;

	dateStream.seekg(dateString.rfind('-')+1);
	dateStream >> buffer;
	result += buffer;

	std::cout << "INT: " << result << '\n';
	return (result);
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
const char*	BitcoinExchange::CannotOpenFileException::what() const throw() {
	return "Error: Could not open file";
}

const char*	BitcoinExchange::TooFewNumbersException::what() const throw() {
	return "Error: Not enough numbers to find span";
}
