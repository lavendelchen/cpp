/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 18:10:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mutant;
	for (int i = 0; i < 5; i++) {
		mutant.push(i);
	}

	MutantStack<int>::const_iterator iter = mutant.begin();
	for (; iter != mutant.end(); iter++) {
		std::cout << *iter << '\n';
	}
}
