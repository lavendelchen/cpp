/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:37:50 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 22:20:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	Zombie* eldia = zombieHorde(5, "Eren Jaeger");
	Zombie* marley = zombieHorde(10, "Theo Magath");
	for (int i = 0; i < 5; i++) {
		eldia[i].announce();
	}
	for (int i = 0; i < 10; i++) {
		marley[i].announce();
	}
	delete [] eldia;
	delete [] marley;
	return (0);
}