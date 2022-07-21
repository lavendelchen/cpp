/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:01:52 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 23:22:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
	return (this->type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::Weapon(std::string type) {
	this->type = type;
}