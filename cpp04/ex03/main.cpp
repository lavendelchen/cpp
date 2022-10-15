/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 00:25:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>
#include <string>

int main(void) {
	Character laufey("Laufey");
	Character dodie(laufey);
	dodie.setName("Dodie");

	std::cout << dodie << '\n';
	std::cout << laufey << '\n';

	Cure* pill = new Cure;
	Ice* cube = new Ice;

	laufey.equip(pill);
	dodie.equip(cube);
	Character jacobCollier;
	jacobCollier = dodie;
	jacobCollier.setName("Jacob Collier");
	std::cout << laufey << '\n';
	std::cout << dodie << '\n';
	std::cout << jacobCollier << '\n';

	dodie.use(2, laufey);
	dodie.use(0, laufey);
	laufey.use(0, laufey);

	laufey.unequip(4);
	laufey.unequip(-3);
	laufey.unequip(2);
	std::cout << laufey << '\n';

	laufey.unequip(0);
	std::cout << laufey << '\n';
	delete pill;
}
