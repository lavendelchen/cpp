/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/07 18:43:12 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		static const unsigned int	ideaNum = 100;
		std::string					ideas[ideaNum];
		unsigned int				index;

	public:
		Brain();
		Brain(Brain const &orig);
		Brain& operator=(Brain const &rhs);
		~Brain();

		void				printAttributes(std::ostream &out);
		void				addIdea(std::string& idea);
		const std::string&	getIdea(unsigned int index);
};

std::ostream&	operator<<(std::ostream &out, Brain &brain);

#endif