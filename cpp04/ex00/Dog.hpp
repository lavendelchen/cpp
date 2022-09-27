/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 23:42:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class Dog: virtual public ClapTrap {
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &orig);
		Dog& operator=(Dog const &rhs);
		~Dog();

		void highFivesGuys(void);
};

std::ostream&	operator<<(std::ostream &out, Dog &fragTrap);

#endif