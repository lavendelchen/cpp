/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 18:52:46 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "MutantStack.hpp"

void	intTest(void) {
	std::cout << "INT TEST\n\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << '\n';
	mstack.pop();
	std::cout << "Size: " << mstack.size() << '\n';
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iterate from beginning to end: \n";
	while (it != ite) {
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int> s(mstack);
}

void	strTest(void) {
	std::cout << "\nSTRING TEST\n\n";
	MutantStack<std::string>	strStack;
	std::cout << "Is empty? " << strStack.empty() << '\n';
	strStack.push("When I was");
	strStack.push("a young boy");
	strStack.push("my father");
	strStack.push("took me into the city");
	strStack.push("to see a marching band");
	std::cout << "Is empty? " << strStack.empty() << '\n';
	MutantStack<std::string>::const_iterator it = strStack.begin();
	MutantStack<std::string>::const_iterator ite = strStack.end();
	++it;
	--it;
	std::cout << "\nConst Iteration: \n";
	while (it != ite) {
		std::cout << *it << '\n';
		++it;
	}
	MutantStack<std::string>	copyStack(strStack);
	MutantStack<std::string>::reverse_iterator it2 = copyStack.rbegin();
	MutantStack<std::string>::reverse_iterator ite2 = copyStack.rend();
	++it2;
	--it2;
	std::cout << "\nReverse Iteration of copied mutant: \n";
	while (it2 != ite2) {
		std::cout << *it2 << '\n';
		++it2;
	}

	MutantStack<std::string>	assignmentStack = copyStack;
	MutantStack<std::string>::const_reverse_iterator it3 = assignmentStack.rbegin();
	MutantStack<std::string>::const_reverse_iterator ite3 = assignmentStack.rend();
	++it3;
	--it3;
	std::cout << "\nConst Reverse Iteration of assignment mutant: \n";
	while (it3 != ite3) {
		std::cout << *it3 << '\n';
		++it3;
	}
}

int main()
{
	intTest();
	strTest();
	return 0;
}
