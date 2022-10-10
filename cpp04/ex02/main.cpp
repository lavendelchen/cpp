/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/10 16:29:59 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongClasses/WrongAnimal.hpp"
#include "WrongClasses/WrongDog.hpp"
#include "WrongClasses/WrongCat.hpp"

int main() {
	const int	loop = 10;
	int			i;
	Animal		*catsAndDogs[loop];

	for(i = 0; i < loop / 2; i++) {
		catsAndDogs[i] = new Cat;
	}
	for(; i < loop; i++) {
		catsAndDogs[i] = new Dog;
	}
	for(i = 0; i < loop; i++) {
		delete catsAndDogs[i];
	}

	Cat* cat1 = new Cat;
	cat1->addIdea("i want to eat");
	cat1->addIdea("i want to sleep");
	cat1->addIdea("i want to play");
	std::cout << "CAT1: " << *cat1 << std::endl;
	Cat* cat2 = new Cat(*cat1);
	delete cat1;
	std::cout << "CAT2: " << *cat2 << std::endl;
	std::cout << "Cat2 Idea 1: " << cat2->getIdea(2) << std::endl;
	delete cat2;
	return 0;
}
