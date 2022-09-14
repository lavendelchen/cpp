/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:01:51 by shaas             #+#    #+#             */
/*   Updated: 2022/09/14 23:42:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <string>
# include <cmath>

class ClapTrap {
	private:
		int					rawBits;
		static const int	rhsBits = 8;

	public:
		ClapTrap();
		ClapTrap(ClapTrap const &orig);
		ClapTrap(const int num);
		ClapTrap(const float num);
		~ClapTrap();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static ClapTrap&		min(ClapTrap &num1, ClapTrap &num2);
		const static ClapTrap&	min(const ClapTrap &num1, const ClapTrap &num2);
		static ClapTrap&		max(ClapTrap &num1, ClapTrap &num2);
		const static ClapTrap&	max(const ClapTrap &num1, const ClapTrap &num2);

		ClapTrap&	operator=(ClapTrap const &rhs);
		bool	operator>(ClapTrap const &rhs);
		bool	operator<(ClapTrap const &rhs);
		bool	operator>=(ClapTrap const &rhs);
		bool	operator<=(ClapTrap const &rhs);
		bool	operator==(ClapTrap const &rhs);
		bool	operator!=(ClapTrap const &rhs);
		ClapTrap	operator+(ClapTrap const &rhs);
		ClapTrap	operator-(ClapTrap const &rhs);
		ClapTrap	operator*(ClapTrap const &rhs);
		ClapTrap	operator/(ClapTrap const &rhs);
		ClapTrap&	operator++();
		ClapTrap	operator++(int);
		ClapTrap&	operator--();
		ClapTrap	operator--(int);
};

std::ostream&	operator<<(std::ostream &out, ClapTrap const &ClapTrap);

#endif