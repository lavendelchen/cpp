/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 17:09:51 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MutantStack.hpp"

int main()
{
	MutantStack sp = MutantStack(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestMutantStack() << std::endl;
	std::cout << sp.longestMutantStack() << std::endl;

	std::vector<int> vector;
	for (int i = 0; i < 6; i++) {
		vector.push_back(i);
	}
	MutantStack sp2(6);
	sp2.addRangeOfNumbers(vector.begin(), vector.end());
	std::cout << sp2.shortestMutantStack() << "   " << sp2.longestMutantStack();
	return 0;
}
