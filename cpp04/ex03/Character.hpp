/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 00:26:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character: virtual public ICharacter {
	private:
		std::string			name;
		static const int	inventorySize = 4;
		AMateria*			inventory[inventorySize];

	public:
		Character();
		Character(std::string name);
		Character(const Character &orig);
		Character& operator=(const Character &rhs);
		~Character();

		void				printAttributes(std::ostream &out);
		void				setName(std::string name);
		const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

std::ostream&	operator<<(std::ostream &out, Character &character);

#endif