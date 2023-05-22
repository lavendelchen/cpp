/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/22 19:22:19 by shaas            ###   ########.fr       */
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

		void	parseDatabase(std::string &databaseFile);
		int		dateIntConverter(std::string dateString);

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
		class InputFileErrorException: public std::exception {
			public:
				const char* what() const throw();
		};
		class BadInputErrorException: public InputFileErrorException {
			private:
				std::string	badInput;
			public:
				BadInputErrorException(std::string badInput);
				const char* what() const throw();
		};
};

#endif