/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:22:50 by shaas             #+#    #+#             */
/*   Updated: 2022/09/15 16:54:02 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap FragmentedRobot("Fragmented Robot");
	FragTrap MoreFragmentedRobot(FragmentedRobot);
	FragTrap MostFragmentedRobot;
	MostFragmentedRobot = FragmentedRobot;

	std::cout << FragmentedRobot;
	std::cout << MoreFragmentedRobot;
	std::cout << MostFragmentedRobot;

	FragmentedRobot.attack("the big bad guy");
	std::cout << FragmentedRobot;

	FragmentedRobot.takeDamage(2);
	std::cout << FragmentedRobot;

	FragmentedRobot.beRepaired(1);
	std::cout << FragmentedRobot;

	FragmentedRobot.takeDamage(200);
	std::cout << FragmentedRobot;

	FragmentedRobot.attack("the big bad guy");
	FragmentedRobot.beRepaired(20);

	FragmentedRobot.highFivesGuys();

	return (0);
}