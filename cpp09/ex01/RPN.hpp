/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2023/05/30 21:09:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string> //remove!
# include <iostream>
# include <sstream>
# include <fstream>
# include <stack>
# include <cctype>

class RPN {
	private:
		bool	isOperator(char c);
		void	operate(std::stack<int>& operands, char operatorr);

	public:
		RPN();
		RPN(const RPN &orig);
		RPN& operator=(const RPN &rhs);
		~RPN();

		int	calculate(const std::string expression);
};

#endif