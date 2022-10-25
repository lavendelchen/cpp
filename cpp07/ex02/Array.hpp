/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:45:13 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 23:47:16 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array {
	private:
		T*		arr;
		uint	arrSize;

	public:
		Array();
		Array(uint n);
		Array(const Array& orig);
		Array& operator=(const Array& rhs);
		~Array();

		uint	size() const;

		T&			operator[](uint index);
		const T&	operator[](uint index) const;

		class IndexOutOfBoundsException: public std::exception {
			public:
				const char* what() const throw();
		};
};

template <typename T>
std::ostream&	operator<<(std::ostream &out, Array<T> &array);

#include "Array.tpp"