/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/18 23:26:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

# define SIGN 0
# define EXECUTE 1

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			grade[2];
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

	public:
		Form();
		Form(std::string name, int grade);
		Form(const Form &orig);
		Form& operator=(const Form &rhs);
		~Form();

		void				printAttributes(std::ostream &out);
		const std::string&	getName(void) const;
		bool				getSignStatus(void) const;
		int					getSignGrade(void) const;
		int					getExecutionGrade(void) const;

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