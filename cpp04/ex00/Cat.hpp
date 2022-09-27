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

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class Cat: virtual public ClapTrap {
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &orig);
		Cat& operator=(Cat const &rhs);
		~Cat();

		void guardGate();
};

std::ostream&	operator<<(std::ostream &out, Cat &Cat);

#endif
