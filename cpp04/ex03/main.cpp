/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 00:56:11 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

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

	MateriaSource	source;
	source.learnMateria(cube);
	source.learnMateria(pill);
	std::cout << source << '\n';

	AMateria*	iWantACure = source.createMateria("cure");
	AMateria*	iWantWeirdStuff = source.createMateria("kjefkjef");
	std::cout << *iWantACure << '\n';
	std::cout << iWantWeirdStuff << '\n';

	delete pill;
	delete iWantACure;
	delete iWantWeirdStuff;
}
