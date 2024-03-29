/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/02 20:11:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(Animal const &orig);
		Animal& operator=(Animal const &rhs);
		virtual ~Animal();

		virtual void		printAttributes(std::ostream &out);
		const std::string	getType(void);
		virtual void		makeSound() const;
};

std::ostream&	operator<<(std::ostream &out, Animal &animal);

#endif