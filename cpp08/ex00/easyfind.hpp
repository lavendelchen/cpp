/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:58:54 by shaas             #+#    #+#             */
/*   Updated: 2022/10/29 20:07:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>

class	NoOccurenceFoundException: public std::exception {
	public:
		const char*	what() const throw() {
			return ("Error: No occurence of i found");
		}
};

template <typename T>
typename T::const_iterator	easyfind(const T& container, int i) {
	typename T::const_iterator iter = std::find(container.begin(), container.end(), i);

	if (iter == container.end())
		throw NoOccurenceFoundException();
	return (iter);
}