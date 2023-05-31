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

class PmergeMe {
	private:
		void	inputErrorCheck(char* input[]);
		void	mergeMe_deque(char* input[]);
		void	mergeMe_vector(char* input[]);
		void	inputParsing(char* input[], std::deque<int>& sequence);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe& operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	mergeMe(char* input[]);
};

#endif