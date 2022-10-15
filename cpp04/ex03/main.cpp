/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 21:48:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include <iostream>
#include <string>

int main(void) {
	Ice zapfen;
	Ice wuerfel(zapfen);
	Ice creme;
	creme = zapfen;

	std::cout << creme << '\n';
	std::cout << wuerfel << '\n';
	std::cout << zapfen << '\n';
	std::cout << creme.getType() << '\n';
	
	AMateria* wasser = zapfen.clone();
	delete wasser;
}
