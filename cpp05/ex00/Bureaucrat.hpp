/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/16 00:26:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &orig);
		Bureaucrat& operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		void	printAttributes(std::ostream &out);
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif