/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2023/05/11 21:20:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try {
		sp.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	sp.addNumber(6);
	try {
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	sp.addNumber(3);
	try {
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> vector;
	for (int i = 0; i < 10; i++) {
		vector.push_back(i);
	}
	Span sp2(5);
	try {
		sp2.addRangeOfNumbers(vector.begin(), vector.end());
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << sp2.shortestSpan() << "   " << sp2.longestSpan() << '\n';
	try {
		sp2.addNumber(3);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}
