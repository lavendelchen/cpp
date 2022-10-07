/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/07 18:45:00 by shaas            ###   ########.fr       */
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
	Cat* cat2 = new Cat(*cat1);
	delete cat1;
	std::cout << "CAT2: " << *cat2 << std::endl;
	delete cat2;
	return 0;
}
