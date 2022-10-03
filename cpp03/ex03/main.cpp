/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 18:05:39 by shaas            ###   ########.fr       */
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

	std::cout << expensiveRobot << '\n';
	std::cout << moreExpensiveRobot << '\n';
	std::cout << mostExpensiveRobot << '\n';

	expensiveRobot.attack("the big bad guy");
	std::cout << '\n' << expensiveRobot << '\n';

	expensiveRobot.ClapTrap::attack("some weirdo");
	std::cout << '\n' << expensiveRobot << '\n';

	expensiveRobot.takeDamage(2);
	std::cout << '\n' << expensiveRobot << '\n';

	expensiveRobot.beRepaired(1);
	std::cout << '\n' << expensiveRobot << '\n';

	expensiveRobot.takeDamage(200);
	std::cout << '\n' << expensiveRobot << '\n';

	expensiveRobot.attack("the big bad guy");
	expensiveRobot.beRepaired(20);

	expensiveRobot.whoAmI();

	return (0);
}