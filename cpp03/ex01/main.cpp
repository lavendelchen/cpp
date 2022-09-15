/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 16:18:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scavvyRobot("Scavvy Robot");
	ScavTrap scavvierRobot(scavvyRobot);
	ScavTrap scavviestRobot;
	scavviestRobot = scavvyRobot;

	std::cout << scavvyRobot;
	std::cout << scavvierRobot;
	std::cout << scavviestRobot;

	scavvyRobot.attack("the big bad guy");
	std::cout << scavvyRobot;

	scavvyRobot.takeDamage(2);
	std::cout << scavvyRobot;

	scavvyRobot.beRepaired(1);
	std::cout << scavvyRobot;

	scavvyRobot.takeDamage(200);
	std::cout << scavvyRobot;

	scavvyRobot.attack("the big bad guy");
	scavvyRobot.beRepaired(20);

	scavvyRobot.guardGate();

	return (0);
}