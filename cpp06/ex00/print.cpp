/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:13:41 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 20:05:24 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

static bool	charOverflow(short argType, tTypes &types) {
	if (argType == INT && (types.i > CHAR_MAX || types.i < CHAR_MIN))
		return true;
	else if (argType == FLOAT && (types.f > CHAR_MAX || types.f < CHAR_MIN))
		return true;
	else if (argType == DOUBLE && (types.d > CHAR_MAX || types.d < CHAR_MIN))
		return true;
	return false;
}

static bool	intOverflow(short argType, tTypes &types) {
	if (argType == FLOAT && (types.f > INT_MAX || types.f < INT_MIN))
		return true;
	else if (argType == DOUBLE && (types.d > INT_MAX || types.d < INT_MIN))
		return true;
	return false;
}

void	print(short argType, tTypes &types) {
	if (argType >= SPECIAL_FLOAT || charOverflow(argType, types))
		std::cout << "\nchar: impossible";
	else
		isprint(types.c) ? std::cout << "\nchar: '" << types.c << "'" : std::cout << "\nchar: Non displayable";
	if (argType >= SPECIAL_FLOAT || intOverflow(argType, types))
		std::cout << "\nint: impossible";
	else
		std::cout << "\nint: " << types.i;
	std::cout << "\nfloat: " << std::fixed << types.f << 'f';
	std::cout << "\ndouble: " << std::fixed << types.d;
	std::cout << '\n';
}
