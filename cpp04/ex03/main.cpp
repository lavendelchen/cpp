/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:45:53 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:08:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>

int main(void) {
	Cure tabletten;
	Cure saft(tabletten);
	Cure zaepfchen;
	zaepfchen = tabletten;

	std::cout << zaepfchen << '\n';
	std::cout << saft << '\n';
	std::cout << tabletten << '\n';
	std::cout << zaepfchen.getType() << '\n';
	
	AMateria* spritze = tabletten.clone();
	delete spritze;
}
