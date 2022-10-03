/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/03 18:05:00 by shaas            ###   ########.fr       */
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

	std::cout << fragmentedRobot << '\n';
	std::cout << moreFragmentedRobot << '\n';
	std::cout << mostFragmentedRobot << '\n';

	fragmentedRobot.attack("the big bad guy");
	std::cout << '\n' << fragmentedRobot << '\n';

	fragmentedRobot.takeDamage(2);
	std::cout << '\n' << fragmentedRobot << '\n';

	fragmentedRobot.beRepaired(1);
	std::cout << '\n' << fragmentedRobot << '\n';

	fragmentedRobot.takeDamage(200);
	std::cout << '\n' << fragmentedRobot << '\n';

	fragmentedRobot.attack("the big bad guy");
	fragmentedRobot.beRepaired(20);

	fragmentedRobot.highFivesGuys();

	return (0);
}