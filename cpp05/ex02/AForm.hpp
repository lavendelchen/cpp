/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 20:31:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define SIGN 0
# define EXE 1

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			exeGrade;

	public:
		AForm();
		AForm(std::string name, bool isSigned, int signGrade, int exeGrade);
		AForm(const AForm &orig);
		AForm& operator=(const AForm &rhs);
		~AForm();

		void				printAttributes(std::ostream &out) const;
		const std::string&	getName(void) const;
		bool				getSignStatus(void) const;
		int					getSignGrade(void) const;
		int					getExeGrade(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, AForm &aform);

#endif