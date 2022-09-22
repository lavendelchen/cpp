/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:32:20 by shaas             #+#    #+#             */
/*   Updated: 2022/09/22 23:17:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void	setFirstName(const std::string &firstName) { this->firstName = firstName; }
		void	setLastName(const std::string &lastName) { this->lastName = lastName; }
		void	setNickname(const std::string &nickname) { this->nickname = nickname; }
		void	setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
		void	setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

		const std::string	&getFirstName(void) const { return this->firstName; }
		const std::string	&getLastName(void) const { return this->lastName; }
		const std::string	&getNickname(void) const { return this->nickname; }
		const std::string	&getPhoneNumber(void) const { return this->phoneNumber; }
		const std::string	&getDarkestSecret(void) const { return this->darkestSecret; }
		
} ;

#endif
