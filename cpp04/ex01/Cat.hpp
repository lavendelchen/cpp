/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/02 20:12:40 by shaas            ###   ########.fr       */
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
		~Cat();

		virtual void	printAttributes(std::ostream &out);
		void			makeSound() const;
};

std::ostream&	operator<<(std::ostream &out, Cat &cat);

#endif
