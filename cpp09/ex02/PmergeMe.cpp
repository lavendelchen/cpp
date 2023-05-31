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

/* -------------------------------- PUBLIC METHODS -------------------------------- */
void	PmergeMe::mergeMe(char* intSequence[]) {

	//check for duplicates at insertion
	//check if is positive number
	//check if too big
	std::cout << "Before:	";
	for (int i = 0; intSequence[i] != NULL; i++) {
		std::cout << intSequence[i] << ' ';
	}
	std::cout << '\n';
}

/* -------------------------------- EXCEPTION METHODS -------------------------------- */
