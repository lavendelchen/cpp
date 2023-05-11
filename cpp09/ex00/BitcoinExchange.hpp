/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/11 22:11:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange {
	private:
		std::string						inputFile;
		std::string						databaseFile;
		std::map<std::string, double>	database;

		void parseDatabase(void);

		BitcoinExchange();

	public:
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange &orig);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		void	addNumber(int num);
		void	addRangeOfNumbers(std::vector<int>::const_iterator start,
									std::vector<int>::const_iterator end);
		int		shortestBitcoinExchange(void);
		int		longestBitcoinExchange(void) const;

		class CannotOpenFileException: public std::exception {
			public:
				const char* what() const throw();
		};
		class TooFewNumbersException: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif