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

/* -------------------------------- PRIVATE METHODS -------------------------------- */
void	BitcoinExchange::parseDatabase(std::string &databaseFile) {
	std::ifstream	dataStream(databaseFile.c_str());
	if (!dataStream.is_open()) {
		throw CannotOpenFileException();
	}

	std::string			buffer;
	std::stringstream	bufferStream;
	int					date;
	float				rate;

	std::getline(dataStream, buffer);
	while (std::getline(dataStream, buffer)) {
		date = dateIntConverter(buffer);

		bufferStream.clear();
		bufferStream << buffer.substr(buffer.find(',')+1);
		bufferStream >> rate;

		this->database.insert(std::pair<int, float>(date, rate));
	}

	for (std::map<int, float>::iterator i = database.begin(); i != database.end(); i++) {
		std::cout << i->first << " | " << i->second << '\n';
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

	return (result);
}

void	BitcoinExchange::checkFormatErrors(std::string& line) {
	unsigned long i					= 0;
	unsigned long separatorIndex	= line.find(" | ");
	unsigned long valueLength		= 0;

	if (separatorIndex == std::string::npos)
		throw BadInputErrorException(line);
	for (;line[i] != '-'; i++) {
		if (!std::isdigit(line[i]))
			throw BadInputErrorException(line);
	}
	i++;
	for (;line[i] != '-'; i++) {
		if (!std::isdigit(line[i]))
			throw BadInputErrorException(line);
	}
	i++;
	for (;i < separatorIndex; i++) {
		if (!std::isdigit(line[i]))
			throw BadInputErrorException(line);
	}
	i+=3;
	if (line[i] == '-')
		throw NegativeNumberErrorException();
	for (;line[i] != '\0'; i++, valueLength++) {
		if (!std::isdigit(line[i]))
			throw BadInputErrorException(line);
	}
	if (valueLength > 10)
		throw LargeNumberErrorException();
}

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	BitcoinExchange::doYaThing(std::string inputFile) {
	if (this->database.empty())
		throw EmptyDatabaseException();
	std::ifstream	inputStream(inputFile.c_str());
	if (!inputStream.is_open()) {
		throw CannotOpenFileException();
	}

	std::string	buffer;
	std::getline(inputStream, buffer);

	while (std::getline(inputStream, buffer)) {
		try {
			this->checkFormatErrors(buffer);
		}
		catch (InputFileErrorException& e) {
			std::cout << e.what() << '\n';
		}
	}
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
const char*	BitcoinExchange::CannotOpenFileException::what() const throw() {
	return "Error: Could not open file";
}

const char*	BitcoinExchange::EmptyDatabaseException::what() const throw() {
	return "Error: no data could be extracted from the database file, so no values can be evaluated.";
}

BitcoinExchange::InputFileErrorException():
	std::logic_error("Error: This line has some problem.") {}

BitcoinExchange::BadInputErrorException(const std::string& badInput):
	std::logic_error("Error: bad input => " + badInput) {}

const char*	BitcoinExchange::LargeNumberErrorException::what() const throw() {
	return "Error: too large a number.";
}

const char*	BitcoinExchange::NegativeNumberErrorException::what() const throw() {
	return "Error: not a positive number.";
}
