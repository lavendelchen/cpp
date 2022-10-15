/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 22:00:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure: virtual public AMateria {
	private:

	public:
		Cure();
		Cure(const Cure &orig);
		Cure& operator=(const Cure &rhs);
		~Cure();

		void		printAttributes(std::ostream &out);
		AMateria*	clone() const;
//		void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream &out, Cure &cure);

#endif
