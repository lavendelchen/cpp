/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/09/22 21:33:48 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap fragmentedRobot("fragmented Robot");
	FragTrap moreFragmentedRobot(fragmentedRobot);
	FragTrap mostFragmentedRobot;
	mostFragmentedRobot = fragmentedRobot;

	std::cout << fragmentedRobot;
	std::cout << moreFragmentedRobot;
	std::cout << mostFragmentedRobot;

	fragmentedRobot.attack("the big bad guy");
	std::cout << fragmentedRobot;

	fragmentedRobot.takeDamage(2);
	std::cout << fragmentedRobot;

	fragmentedRobot.beRepaired(1);
	std::cout << fragmentedRobot;

	fragmentedRobot.takeDamage(200);
	std::cout << fragmentedRobot;

	fragmentedRobot.attack("the big bad guy");
	fragmentedRobot.beRepaired(20);

	fragmentedRobot.highFivesGuys();

	return (0);
}