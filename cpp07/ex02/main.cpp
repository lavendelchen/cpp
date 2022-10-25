/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/26 00:01:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

void	intTest(void) {
	std::cout << "\nINT TEST\n";
	Array<int>	intArr1;
	std::cout << intArr1 << '\n';

	Array<int>	intArr2(5);

	for (int i = 0; i < 5; i++) {
		intArr2[i] = i;
	}

	Array<int> intArr3(intArr2);
	intArr1 = intArr2;

	std::cout << intArr2 << '\n';
	std::cout << intArr3 << '\n';
	std::cout << intArr1 << '\n';

	try {
		intArr2[100];
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

void doubleTest(void)
{
	std::cout << "\n\nDOUBLE TEST\n";
	Array<double> doubleArr1;
	std::cout << doubleArr1 << '\n';

	Array<double> doubleArr2(5);

	for (int i = 0; i < 5; i++)
	{
		doubleArr2[i] = i + 0.9834783;
	}

	Array<double> doubleArr3(doubleArr2);
	doubleArr1 = doubleArr2;

	std::cout << doubleArr2 << '\n';
	std::cout << doubleArr3 << '\n';
	std::cout << doubleArr1 << '\n';

	try
	{
		doubleArr2[100];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}

void stringTest(void)
{
	std::cout << "\n\nSTRING TEST\n";
	Array<std::string> stringArr1;
	std::cout << stringArr1 << '\n';

	Array<std::string> stringArr2(5);

	for (int i = 0; i < 5; i++)
	{
		stringArr2[i] = 'A' + i;
	}

	Array<std::string> stringArr3(stringArr2);
	stringArr1 = stringArr2;

	std::cout << stringArr2 << '\n';
	std::cout << stringArr3 << '\n';
	std::cout << stringArr1 << '\n';

	try
	{
		stringArr2[100];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}

int	main(void) {
	intTest();
	doubleTest();
	stringTest();
	return 0;
}
