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

# include <string> // remove
# include <iostream>
# include <stack>
# include <cctype>

class PmergeMe {
	private:
		bool	isOperator(char c);
		void	operate(std::stack<int>& operands, char operatorr);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe& operator=(const PmergeMe &rhs);
		~PmergeMe();

		int	calculate(const std::string expression);
};

#endif