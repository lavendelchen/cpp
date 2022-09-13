/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 00:08:17 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	private:
		int					rawBits;
		static const int	rhsBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &orig);
		Fixed(const int rawBits);
		~Fixed();

		Fixed&	operator=(Fixed const &rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif