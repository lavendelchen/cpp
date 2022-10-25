/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:12:38 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 18:12:59 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

void	convert(short argType, tTypes &types, char* arg[]) {
	switch (argType) {
		case CHAR: std::cout << "CHAR\n";
			types.c = arg[1][0];
			types.i = static_cast<int>(types.c);
			types.f = static_cast<float>(types.c);
			types.d = static_cast<double>(types.c);
			break;
		case INT: std::cout << "INT\n";
			types.i = atoi(arg[1]);
			types.c = static_cast<char>(types.i);
			types.f = static_cast<float>(types.i);
			types.d = static_cast<double>(types.i);
			break;
		case FLOAT: std::cout << "FLOAT\n";
			types.f = atof(arg[1]);
			types.c = static_cast<char>(types.f);
			types.i = static_cast<int>(types.f);
			types.d = static_cast<double>(types.f);
			break;
		case DOUBLE: std::cout << "DOUBLE\n";
			types.d = atof(arg[1]);
			types.c = static_cast<char>(types.d);
			types.i = static_cast<int>(types.d);
			types.f = static_cast<float>(types.d);
			break;
		case SPECIAL_FLOAT: std::cout << "SPECIAL_FLOAT\n";
			break;
		case SPECIAL_DOUBLE: std::cout << "SPECIAL_DOUBLE\n";
			break;
	}
}
