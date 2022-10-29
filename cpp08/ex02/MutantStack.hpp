/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 18:08:48 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	private:

	public:
		MutantStack(): std::stack<T>() {};
		MutantStack(const MutantStack &orig): std::stack<T>(orig) {};
		MutantStack& operator=(const MutantStack &rhs) {
			if (this != &rhs) {
				this->c = rhs.c;
			}
			return *this;
		};
		~MutantStack() {};

		/* ITERATORS */
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
	
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { this->c.begin(); }
		const_iterator end() const { this->c.end(); }
	
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
	
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif