/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:15:51 by shaas             #+#    #+#             */
/*   Updated: 2022/10/21 02:31:05 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: virtual public AForm {
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &orig);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		void			printAttributes(std::ostream &out) const;
		void			execute(const Bureaucrat& executor) const;
		static AForm*	createNew(std::string target);
};

std::ostream&	operator<<(std::ostream &out, PresidentialPardonForm &form);

#endif