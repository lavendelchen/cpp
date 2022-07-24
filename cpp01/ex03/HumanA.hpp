/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:10:59 by shaas             #+#    #+#             */
/*   Updated: 2022/07/24 17:28:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon&		weapon;
		std::string	name;

	public:
		HumanA(std::string name, Weapon& weapon);
		void setWeapon(Weapon& weapon);
		void attack();
} ;

#endif