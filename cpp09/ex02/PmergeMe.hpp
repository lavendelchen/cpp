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

# include <string> // check for cpp98
# include <iostream>
# include <deque>
# include <vector>
# include <cctype>
# include <sstream>
# include <limits.h>
# include <algorithm>
//#include <utility>

typedef std::deque<std::pair<int,int> > SortDeque;

class PmergeMe {
	private:
		void		inputErrorCheck(char* input[]);
		void		mergeMe_deque(char* input[]);
		void		mergeMe_vector(char* input[]);
		void		inputParsing(char* input[], SortDeque& sequence);
		bool		isSorted(SortDeque& sequence);
		void		printSequence(std::string printBefore, SortDeque& sequence);
		SortDeque	sortPairs(SortDeque& sequence);
		void		binaryInsert(SortDeque& sequence, SortDeque& mainChain);

		/* stands for Ford-Johnson Merge-Insertion. it's the actual algorithm. */
		void	FJMI(SortDeque& sequence, SortDeque& mainChain);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe& operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	mergeMe(char* input[]);
};

#endif