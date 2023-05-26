/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/26 21:39:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <cctype>

class BitcoinExchange {
	private:
		std::map<int, float>	database;

		void	parseDatabase(std::string& databaseFile);
		int		dateIntConverter(std::string dateString);
		void	checkFormatErrors(std::string& line);

		BitcoinExchange();

	public:
		BitcoinExchange(std::string databaseFile);
		BitcoinExchange(const BitcoinExchange &orig);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		void	doYaThing(std::string inputFile);

		class CannotOpenFileException: public std::exception {
			public:
				const char* what() const throw();
		};
		class EmptyDatabaseException: public std::exception {
			public:
				const char* what() const throw();
		};

		class InputFileErrorException: public std::logic_error {
			public:
				InputFileErrorException();
		};
		class BadInputErrorException: public InputFileErrorException {
			public:
				BadInputErrorException(const std::string& badInput);
		};
		class LargeNumberErrorException: public InputFileErrorException {
			public:
				const char* what() const throw();
		};
		class NegativeNumberErrorException: public InputFileErrorException {
			public:
				const char* what() const throw();
		};
};

#endif