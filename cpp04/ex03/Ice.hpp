/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:00:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice: virtual public AMateria {
	private:

	public:
		Ice();
		Ice(const Ice &orig);
		Ice& operator=(const Ice &rhs);
		~Ice();

		void		printAttributes(std::ostream &out);
		AMateria*	clone() const;
//		void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream &out, Ice &ice);

#endif
