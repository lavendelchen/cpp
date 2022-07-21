/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:10:59 by shaas             #+#    #+#             */
/*   Updated: 2022/07/21 23:23:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanA(std::string name, Weapon weapon);
		void attack();
} ;
