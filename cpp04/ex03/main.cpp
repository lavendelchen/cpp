/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 01:07:58 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>
#include <string>

void myTests(void) {
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
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	std::cout << source << '\n';

	AMateria*	iWantACure = source.createMateria("cure");
	AMateria*	iWantWeirdStuff = source.createMateria("kjefkjef");
	std::cout << *iWantACure << '\n';
	std::cout << iWantWeirdStuff << '\n';

	delete pill;
	delete iWantACure;
	delete iWantWeirdStuff;
}

void testsFromSubject(void) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main(void) {
	std::cout << "-----------MY TESTS-------------\n\n";
	myTests();
	std::cout << "\n-------------TESTS FROM SUBJECT---------\n\n";
	testsFromSubject();
}
