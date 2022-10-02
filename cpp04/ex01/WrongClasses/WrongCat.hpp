/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/01 23:25:55 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &orig);
		WrongCat& operator=(WrongCat const &rhs);
		~WrongCat();

		void	makeSound() const;
};

std::ostream&	operator<<(std::ostream &out, WrongCat &wrongCat);

#endif
