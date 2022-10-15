/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:38:12 by shaas             #+#    #+#             */
/*   Updated: 2022/10/15 23:46:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria &orig);
		AMateria& operator=(const AMateria &rhs);
		virtual ~AMateria();

		virtual void		printAttributes(std::ostream &out);
		const std::string&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream &out, AMateria &aMateria);

#endif