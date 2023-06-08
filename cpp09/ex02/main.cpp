/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2023/06/08 18:12:03 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
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
		PmergeMe merger;
		merger.mergeMe(&argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
