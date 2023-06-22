/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2023/06/22 21:08:11 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PmergeMe.hpp"

int	main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error: Please provide a sequence of positive integers." << std::endl;
		return (1);
	}
	if (argc > 3001) {
		std::cout << "Error: Please provide no more than 3000 different integers." << std::endl;
		return (1);
	}

	try {
		unsigned long timeTaken;
		
		PmergeMe<std::deque<ValueData_deque*>, ValueData_deque> merger;
		timeTaken = merger.mergeMe(&argv[1], true); //set both to false to eliminate print time from comparison.
		std::cout	<< "Time to process a range of " << argc-1 << " elements with std::deque  : "
					<< std::setw(10) << timeTaken << " us\n";

		PmergeMe<std::vector<ValueData_vector*>, ValueData_vector> merger2;
		timeTaken = merger2.mergeMe(&argv[1], false);
		std::cout	<< "Time to process a range of " << argc-1 << " elements with std::vector : "
					<< std::setw(10) << timeTaken << " us\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}

// last number gets deleted????? only at 3 elements! + 7 + 12 ... no idea what the pattrn is there lol but should be resolvable with debugger
// check valgrind
// check pdf
