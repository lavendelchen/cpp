/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 23:29:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>
#include <string>

int main(void) {
	Character laufey;
	Character dodie(laufey);
	Character jacobCollier;
	jacobCollier = laufey;

	std::cout << jacobCollier << '\n';
	std::cout << dodie << '\n';
	std::cout << laufey << '\n';

	Cure	pill;
	Ice		cube;

	laufey.equip(&pill);
	dodie.equip(&cube);
	std::cout << laufey << '\n';
	std::cout << dodie << '\n';

	dodie.use(2, laufey);
	dodie.use(0, laufey);
	laufey.use(0, laufey);

	laufey.unequip(4);
	laufey.unequip(-3);
	laufey.unequip(2);
	std::cout << laufey << '\n';

	laufey.unequip(0);
	std::cout << laufey << '\n';
}
