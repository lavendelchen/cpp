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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &orig);
		Bureaucrat& operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		void				printAttributes(std::ostream &out);
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				incGrade(void);
		void				decGrade(void);
		void				incGrade(const int amount);
		void				decGrade(const int amount);

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif