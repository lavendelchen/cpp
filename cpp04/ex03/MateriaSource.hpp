/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 00:26:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: virtual public IMateriaSource {
	private:
		std::string			name;
		static const int	inventorySize = 4;
		AMateria*			inventory[inventorySize];

	public:
		MateriaSource();
		MateriaSource(std::string name);
		MateriaSource(const MateriaSource &orig);
		MateriaSource& operator=(const MateriaSource &rhs);
		~MateriaSource();

		void		printAttributes(std::ostream &out);
		void		learnMateria(AMateria*);
		AMateria*	createMateria(const std::string& type);
};

std::ostream&	operator<<(std::ostream &out, MateriaSource &materiaSource);

#endif