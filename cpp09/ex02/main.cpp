/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2023/05/31 15:45:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "RPN.hpp"

int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Error: Please provide one expresson." << std::endl;
		return (1);
	}

	try {
		RPN rpn;
		int	result = rpn.calculate(argv[1]);
		std::cout << result << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
