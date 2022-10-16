/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 05:04:49 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: virtual public Animal {
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(Cat const &orig);
		Cat& operator=(Cat const &rhs);
		virtual ~Cat();

		virtual void		printAttributes(std::ostream &out);
		void				makeSound() const;
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int index);
};

std::ostream&	operator<<(std::ostream &out, Cat &cat);

#endif
