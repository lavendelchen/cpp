/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/24 21:28:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

enum types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class InvalidArgumentError: public std::exception {
	public:
		const char* what() const throw() {
			return ("Error: Invalid Argument");
		}
};

bool	isSpecialFloat(char *arg) {
	if (strcmp(arg, "+inff") == 0 ||
		strcmp(arg, "-inff") == 0 ||
		strcmp(arg, "nanf") == 0)
		return true;
	return false;
}

bool	isSpecialDouble(char *arg) {
	if (strcmp(arg, "+inf") == 0 ||
		strcmp(arg, "-inf") == 0 ||
		strcmp(arg, "nan") == 0)
		return true;
	return false;
}

short	findType(char* arg) {
	if (strlen(arg) == 1 && !isdigit(arg[0])) {
		if (!isprint(arg[0]))
			throw InvalidArgumentError();
		return CHAR;
	}
	else if (isSpecialFloat(arg))
		return FLOAT;
	else if (isSpecialDouble(arg))
		return DOUBLE;
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

int main(int argnum, char *arg[]) {
	if (argnum != 2)
		throw(std::runtime_error("Error: 1 argument needed"));

	short type = findType(arg[1]);

	char	c;
	int		i;
	float	f;
	double	d;

	switch (type) {
		case CHAR: std::cout << "CHAR\n";
			c = arg[1][0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT: std::cout << "INT\n";
			i = atoi(arg[1]);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT: std::cout << "FLOAT\n";
			if (isSpecialFloat(arg[1]))
				f = Spec
			f = atof(arg[1]);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE: std::cout << "DOUBLE\n";
			d = atof(arg[1]);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
	}
	isprint(c) ? std::cout << "\nchar: " << c : std::cout << "\nchar: Non displayable";
	std::cout << "\nint: " << i;
	std::cout << "\nfloat: " << f;
	std::cout << "\ndouble: " << d;
	std::cout << '\n';
	return 0;
}
