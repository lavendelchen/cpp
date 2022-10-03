/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 19:32:59 by shaas            ###   ########.fr       */
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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}
