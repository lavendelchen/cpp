/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/19 18:13:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define SIGN 0
# define EXE 1

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			exeGrade;
		static const int	highestGrade = Bureaucrat::highestGrade;
		static const int	lowestGrade = Bureaucrat::lowestGrade;

	public:
		Form();
		Form(std::string name, bool isSigned, int signGrade, int exeGrade);
		Form(const Form &orig);
		Form& operator=(const Form &rhs);
		~Form();

		void				printAttributes(std::ostream &out) const;
		const std::string&	getName(void) const;
		bool				getSignStatus(void) const;
		int					getSignGrade(void) const;
		int					getExeGrade(void) const;

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, Form &form);

#endif