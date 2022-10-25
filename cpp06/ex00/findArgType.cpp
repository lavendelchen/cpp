/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findArgType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:35 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 18:12:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

static bool	isSpecialFloat(char *arg, tTypes& types) {
	if (strcmp(arg, "+inff") == 0) {
		types.f = INFINITY;
		types.d = INFINITY;
		return true;
	}
	if (strcmp(arg, "-inff") == 0) {
		types.f = -INFINITY;
		types.d = -INFINITY;
		return true;
	}
	if (strcmp(arg, "nanf") == 0) {
		types.f = NAN;
		types.d = NAN;
		return true;
	}
	return false;
}

static bool	isSpecialDouble(char *arg, tTypes& types) {
	if (strcmp(arg, "+inf") == 0) {
		types.d = INFINITY;
		types.f = INFINITY;
		return true;
	}
	if (strcmp(arg, "-inf") == 0) {
		types.d = -INFINITY;
		types.f = -INFINITY;
		return true;
	}
	if (strcmp(arg, "nan") == 0) {
		types.d = NAN;
		types.f = NAN;
		return true;
	}
	return false;
}

short	findArgType(char* arg, tTypes& types) {
	if (strlen(arg) == 1 && !isdigit(arg[0])) {
		if (!isprint(arg[0]))
			throw InvalidArgumentError();
		return CHAR;
	}
	else if (isSpecialFloat(arg, types))
		return SPECIAL_FLOAT;
	else if (isSpecialDouble(arg, types))
		return SPECIAL_DOUBLE;
	else if (arg[0] == '-' || isdigit(arg[0])) {
		bool	periodFound = false;
		int i = 1;
		while (arg[i] != '\0') {
			if (!isdigit(arg[i])) {
				if ((size_t)i >= strlen(arg) - 1 && arg[i] == 'f')
					break;
				if (arg[i] != '.' || periodFound == true)
					throw InvalidArgumentError();
				periodFound = true;
			}
			i++;
		}
		if (periodFound == false)
			return INT;
		if (arg[strlen(arg) - 1] != '.' && *(strchr(arg, '.') - 1) != '-') {
			if (arg[strlen(arg) - 1] == 'f')
				return FLOAT;
			return DOUBLE;
		}
	}
	throw InvalidArgumentError();
}
