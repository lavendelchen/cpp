/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/20 22:54:52 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm: virtual public AForm {
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &orig);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		void	printAttributes(std::ostream &out) const;
		void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream &out, ShrubberyCreationForm &form);

#endif