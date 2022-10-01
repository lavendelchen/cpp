/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 23:42:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongDog: virtual public WrongAnimal {
	public:
		WrongDog();
		WrongDog(WrongDog const &orig);
		WrongDog& operator=(WrongDog const &rhs);
		~WrongDog();
	
		void	makeSound() const;
};

std::ostream&	operator<<(std::ostream &out, WrongDog &dog);

#endif