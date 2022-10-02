/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/02 19:30:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		static const int	ideaNum = 100;
		std::string			ideas[ideaNum];

	public:
		Brain();
		Brain(Brain const &orig);
		Brain& operator=(Brain const &rhs);
		~Brain();

		void				printAttributes(std::ostream &out);
		const std::string	getType(void);
};

std::ostream&	operator<<(std::ostream &out, Brain &brain);

#endif