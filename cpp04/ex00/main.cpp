/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 21:22:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	Animal randomAnimal;
	std::cout << randomAnimal << std::endl;

	Dog doggy;
	std::cout << "\n";
	Dog doggggy;
	doggggy = doggy;
	std::cout << "\n";

	Cat cat;
	std::cout << "\n";
	Cat cats;
	cats = cat;
	std::cout << "\n";
	return (0);
}