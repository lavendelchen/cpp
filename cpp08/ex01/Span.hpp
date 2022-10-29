/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 06:15:37 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	private:
		unsigned int		maxElements;
		std::vector<int>	elements;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &orig);
		Span& operator=(const Span &rhs);
		~Span();

		void	addNumber(int num);
		void	addRangeOfNumbers(std::vector<int>::const_iterator start,
									std::vector<int>::const_iterator end);
		int		shortestSpan(void);
		int		longestSpan(void) const;

		class SpanOverflowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class TooFewNumbersException: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif