/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 17:09:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>

class MutantStack {
	private:
		unsigned int		maxElements;
		std::vector<int>	elements;

	public:
		MutantStack();
		MutantStack(unsigned int n);
		MutantStack(const MutantStack &orig);
		MutantStack& operator=(const MutantStack &rhs);
		~MutantStack();

		void	addNumber(int num);
		void	addRangeOfNumbers(std::vector<int>::const_iterator start,
									std::vector<int>::const_iterator end);
		int		shortestMutantStack(void);
		int		longestMutantStack(void) const;

		class MutantStackOverflowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class TooFewNumbersException: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif