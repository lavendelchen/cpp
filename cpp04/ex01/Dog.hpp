/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/07 18:49:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal {
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(Dog const &orig);
		Dog& operator=(Dog const &rhs);
		~Dog();

		virtual void		printAttributes(std::ostream &out);
		void				makeSound() const;
		void				addIdea(std::string& idea);
		const std::string&	getIdea(unsigned int index);
};

std::ostream&	operator<<(std::ostream &out, Dog &dog);

#endif
