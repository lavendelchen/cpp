/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:09:27 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 18:14:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION
# define CONVERSION

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

enum types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL_FLOAT,
	SPECIAL_DOUBLE
};

typedef struct sTypes {
	char	c;
	int		i;
	float	f;
	double	d;
} tTypes;

class InvalidArgumentError: public std::exception {
	public:
		const char* what() const throw() {
			return ("Error: Invalid Argument");
		}
};

short	findArgType(char* arg, tTypes& types);
void	convert(short argType, tTypes &types, char* arg[]);
void	print(short argType, tTypes &types);

#endif