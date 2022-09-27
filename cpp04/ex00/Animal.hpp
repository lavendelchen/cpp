/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 23:42:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		Animal();
		Animal(std::string name);
		Animal(Animal const &orig);
		Animal& operator=(Animal const &rhs);
		~Animal();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printAttributes(std::ostream &out);
};

std::ostream&	operator<<(std::ostream &out, Animal &Animal);

#endif