/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:08:05 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 23:24:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon;
}

HumanA::HumanA(std::string name, Weapon weapon) {
	this->name = name;
	this->weapon = weapon;
}
