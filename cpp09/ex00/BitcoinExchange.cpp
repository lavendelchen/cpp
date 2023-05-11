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
BitcoinExchange::BitcoinExchange(): databaseFile("data.csv") { }

BitcoinExchange::BitcoinExchange(std::string inputFile): databaseFile("data.csv") {
	std::ifstream	fileStream(inputFile);
	if (!fileStream.is_open()) {
		throw CannotOpenFileException();
	}
	this->inputFile = inputFile;
	this->parseDatabase();
	
}

	// std::ifstream	fileStream(fileName);
	// if (fileStream.is_open() == false) {
	// 	cerr	<< "\e[31mError: " << fileName
	// 				<< " couldn't be opened\e[0m" << endl;
	// 	return (true);
	// }

	// stringstream	fileStringStream;
	// fileStringStream << fileStream.rdbuf();
	// fileContent = fileStringStream.str();
	// return (false);

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig): maxElements(orig.maxElements), elements(orig.elements) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->maxElements = rhs.maxElements;
		this->elements = rhs.elements;
	}
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
BitcoinExchange::~BitcoinExchange() { }

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	BitcoinExchange::parseDatabase(void) {
	std::ifstream	dataStream(this->databaseFile);
	if (!dataStream.is_open()) {
		throw CannotOpenFileException();
	}

	std::string	buffer;
	std::getline(dataStream, buffer, '\n');
	while (std::getline(dataStream, buffer, ',')) {
		
	}
	
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
const char*	BitcoinExchange::CannotOpenFileException::what() const throw() {
	return "Error: Could not open file";
}

const char*	BitcoinExchange::TooFewNumbersException::what() const throw() {
	return "Error: Not enough numbers to find span";
}
