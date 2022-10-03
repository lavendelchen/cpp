/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 18:00:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap littleRobot("Little Robot");
	ClapTrap littlerRobot(littleRobot);
	ClapTrap littlestRobot;
	littlestRobot = littleRobot;

	std::cout << littleRobot << '\n';
	std::cout << littlerRobot << '\n';
	std::cout << littlestRobot << '\n';

	littleRobot.attack("the big bad guy");
	std::cout << '\n' << littleRobot << '\n';

	littleRobot.takeDamage(2);
	std::cout << '\n' << littleRobot << '\n';

	littleRobot.beRepaired(1);
	std::cout << '\n' << littleRobot << '\n';

	littleRobot.takeDamage(20);
	std::cout << '\n' << littleRobot << '\n';

	littleRobot.attack("the big bad guy");
	littleRobot.beRepaired(20);

	return (0);
}