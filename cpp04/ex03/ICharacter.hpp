/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:11:50 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:43:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter {
	public:
		virtual ~ICharacter() {}
		//virtual const std::string& getName() const = 0;
		//virtual void equip(AMateria* m) = 0;
		//virtual void unequip(int idx) = 0;
		//virtual void use(int idx, ICharacter& target) = 0;
};

#endif