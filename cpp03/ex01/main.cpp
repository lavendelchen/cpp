/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 17:59:07 by shaas            ###   ########.fr       */
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
	std::cout << '\n' << scavvyRobot << '\n';

	scavvyRobot.takeDamage(2);
	std::cout << '\n' << scavvyRobot << '\n';

	scavvyRobot.beRepaired(1);
	std::cout << '\n' << scavvyRobot << '\n';

	scavvyRobot.takeDamage(200);
	std::cout << '\n' << scavvyRobot << '\n';

	scavvyRobot.attack("the big bad guy");
	scavvyRobot.beRepaired(20);

	scavvyRobot.guardGate();

	return (0);
}