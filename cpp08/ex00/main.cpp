/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 20:14:57 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#include "easyfind.hpp"

int	main(void) {
	std::deque<int> deque;

	std::cout << "Change all occurences on \"deque\" to try different containers\n";

	try {
		std::cout << "\ntry empty deque:\n";
		std::cout << *easyfind(deque, 5);
	}
	catch(std::exception& e) { std::cout << e.what() << '\n'; }

	deque.push_back(5);
	try {
		std::cout << "\ntry one element (easyfind arguments modifiable):\n";
		std::cout << *easyfind(deque, 5) << '\n';
	}
	catch(std::exception& e) { std::cout << e.what() << '\n'; }

	deque.pop_back();
	for (int i = 0; i < 50; i += 5) {
		deque.push_back(i);
	}
	try {
		std::cout << "\ntry multiple elements (easyfind arguments modifiable):\n";
		std::cout << *easyfind(deque, 3) << '\n';
	}
	catch(std::exception& e) { std::cout << e.what() << '\n'; }
	return 0;
}
