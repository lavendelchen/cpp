/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 22:22:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void	addOne(int& num) {
	num++;
}

void	intTest(void) {
	std::cout << "\nINT TEST\n";
	int intArr[] = {1, 2, 3, 4};

	iter(intArr, 4, &addOne);

	for (int i = 0; i < 4; i++)
		std::cout << intArr[i] << ' ';
}

void	divideByTwo(double& num) {
	num /= 2;
}

void	doubleTest(void) {
	std::cout << "\n\nDOUBLE TEST\n";
	double doubleArr[] = {33.3, 66.6, 99.9, 4949.9494};

	iter(doubleArr, 4, &divideByTwo);

	for (int i = 0; i < 4; i++)
		std::cout << doubleArr[i] << ' ';
}

void	uwuSpeak(std::string& str) {
	str.replace(0, 1, "W");
}

void	stringTest(void) {
	std::cout << "\n\nSTRING TEST\n";
	std::string stringArr[] = {"Hello", "World", "I", "Am", "Svenja"};

	iter(stringArr, 5, &uwuSpeak);

	for (int i = 0; i < 5; i++)
		std::cout << stringArr[i] << ' ';
}

int	main(void) {
	intTest();
	doubleTest();
	stringTest();
	return 0;
}
