/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:53:24 by shaas             #+#    #+#             */
/*   Updated: 2022/09/09 09:54:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
	

	public:
		Fixed();
		Fixed(Fixed const &orig);
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );
};

#endif /* *********************************************************** FIXED_H */