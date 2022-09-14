/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 01:42:00 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap littleRobot("Little Robot");
	ClapTrap littlerRobot(littleRobot);
	ClapTrap littlestRobot;
	littlestRobot = littleRobot;

	std::cout << littleRobot;
	std::cout << littlerRobot;
	std::cout << littlestRobot;

	littleRobot.attack("the big bad guy");
	std::cout << littleRobot;

	littleRobot.takeDamage(2);
	std::cout << littleRobot;

	littleRobot.beRepaired(1);
	std::cout << littleRobot;

	littleRobot.takeDamage(20);
	std::cout << littleRobot;

	littleRobot.attack("the big bad guy");
	littleRobot.beRepaired(20);

	return (0);
}