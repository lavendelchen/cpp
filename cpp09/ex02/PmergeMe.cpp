/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:02:02 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 19:01:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------------------- CONSTRUCTOR --------------------------------*/
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &orig) {
	(void)orig;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) { }
	return *this;
}

/* -------------------------------- DESTRUCTOR -------------------------------- */
PmergeMe::~PmergeMe() { }

/* -------------------------------- PRIVATE METHODS -------------------------------- */
bool	PmergeMe::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void	PmergeMe::operate(std::stack<int>& operands, char operatorr) {
	int topOperand = operands.top();
	operands.pop();

	switch (operatorr) {
		case '+':
			operands.top()+=topOperand;
			break;
		case '-':
			operands.top()-=topOperand;
			break;
		case '*':
			operands.top()*=topOperand;
			break;
		case '/':
			operands.top()/=topOperand;
			break;
	}
}

/* -------------------------------- PUBLIC METHODS -------------------------------- */
int	PmergeMe::calculate(const std::string expression) {
	if (expression.empty())
		throw std::logic_error("Error: Given expression is empty.");

	std::stack<int>	operands;

	for (int i = 0; expression[i] != '\0'; i++) {
		if (std::isdigit(expression[i])) {
			operands.push(expression[i] - 48);
		}
		else if (isOperator(expression[i])) {
			if (operands.size() < 2)
				throw std::logic_error("Error: Too many operators, not enough operands.");
			operate(operands, expression[i]);
		}
		else
			throw std::logic_error("Error: Expression can only contain digits, operators and spaces inbetween.");

		i++;
		if (expression[i] == '\0')
			break;
		if (expression[i] != ' ')
			throw std::logic_error("Error: Expected space after operator or single-digit operand.");
	}

	if (operands.size() > 1)
				throw std::logic_error("Error: Too many operands, not enough operators.");
	return (operands.top());
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
