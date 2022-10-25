/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:45:13 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 20:56:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T&	min(T& a, T& b) {
	return (a < b ? a : b);
}

template <typename T>
T&	max(T& a, T& b) {
	return (a > b ? a : b);
}