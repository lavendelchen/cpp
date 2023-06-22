/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/30 21:09:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <ctime>
# include <climits>
# include <algorithm>
# include "ValueData.hpp"

template <typename Sorter, typename ValueData>
class PmergeMe {
	private:
		void			inputErrorCheck(char* input[]);
		void			inputParsing(char* input[], Sorter& sequence);
		bool			isSorted(Sorter& sequence);
		void			printSequence(std::string printBefore, Sorter& sequence);
		void			makePairs(Sorter& sequence, Sorter& greaterSequence, ValueData*& oddLeftover);
		void			binaryInsert(Sorter& mainChain, ValueData*& oddLeftover);
		void			printData(Sorter& sequence);
		void			binarySearch(Sorter& mainChain, ValueData* higher, ValueData* toSort);
		unsigned long	calculateTsToNsec(timespec ts);
		unsigned long	getCurrTime(void);

		/* stands for Ford-Johnson Merge-Insertion. it's the actual algorithm. */
		void	FJMI(Sorter& sequence, Sorter& mainChain);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe& operator=(const PmergeMe &rhs);
		~PmergeMe();

		unsigned long	mergeMe(char* input[], bool print);
};

#include "PmergeMe.tpp"

#endif