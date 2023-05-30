/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/30 03:08:56 by shaas            ###   ########.fr       */
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
		float	stringToFloat(std::string floatString);
		float	findExchangeRate(int date);

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

		class LineProcessingException: public std::logic_error {
			public:
				LineProcessingException();
				LineProcessingException(const std::string& whatArg);
		};
		class BadInputErrorException: public LineProcessingException {
			public:
				BadInputErrorException(const std::string& badInput);
		};
		class LargeNumberErrorException: public LineProcessingException {
			public:
				const char* what() const throw();
		};
		class NegativeNumberErrorException: public LineProcessingException {
			public:
				const char* what() const throw();
		};

		class NoEarlierDateException: public LineProcessingException {
			public:
				const char* what() const throw();
		};
};

#endif