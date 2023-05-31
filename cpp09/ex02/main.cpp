/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2023/05/31 16:08:58 by shaas            ###   ########.fr       */
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

	try {
		PmergeMe merger;
		merger.mergeMe(&argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
