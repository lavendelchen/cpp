/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:55:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongClasses/WrongAnimal.hpp"
#include "WrongClasses/WrongDog.hpp"
#include "WrongClasses/WrongCat.hpp"

int main() {
	{
		std::cout << "-----CORRECT USAGE-----\n\n";
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();
	
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
	
		i->makeSound();
		j->makeSound();
		meta->makeSound();
	
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << "\n-----WRONG USAGE-----\n\n";
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* j = new WrongDog();
		WrongAnimal* i = new WrongCat();
	
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
	
		i->makeSound();
		j->makeSound();
		meta->makeSound();
	
		delete i;
		delete j;
		delete meta;
	}
	return 0;
}
