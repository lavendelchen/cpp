/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:35 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 21:25:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main(void) { // why memleak??????
	Zombie mike = Zombie("Mike");
	mike.announce();

	randomChump("Lucas");

	Zombie* dustin = newZombie("Dustin");
	dustin->announce();
	delete dustin;

	return (0);
}