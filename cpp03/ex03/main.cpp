/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/09/27 20:58:30 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap expensiveRobot("expensive robot");
	DiamondTrap moreExpensiveRobot(expensiveRobot);
	DiamondTrap mostExpensiveRobot;
	mostExpensiveRobot = expensiveRobot;

	std::cout << expensiveRobot;
	std::cout << moreExpensiveRobot;
	std::cout << mostExpensiveRobot;

	expensiveRobot.attack("the big bad guy");
	std::cout << expensiveRobot;

	expensiveRobot.ClapTrap::attack("some weirdo");
	std::cout << expensiveRobot;

	expensiveRobot.takeDamage(2);
	std::cout << expensiveRobot;

	expensiveRobot.beRepaired(1);
	std::cout << expensiveRobot;

	expensiveRobot.takeDamage(200);
	std::cout << expensiveRobot;

	expensiveRobot.attack("the big bad guy");
	expensiveRobot.beRepaired(20);

	expensiveRobot.whoAmI();

	return (0);
}