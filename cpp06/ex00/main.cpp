/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/25 18:18:49 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argNum, char *arg[]) {
	try {
		if (argNum != 2)
			throw(std::runtime_error("Error: 1 argument needed"));

		tTypes types;

		short argType = findArgType(arg[1], types);
		convert(argType, types, arg);
		print(argType, types);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}
