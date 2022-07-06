/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:32:20 by shaas             #+#    #+#             */
/*   Updated: 2022/07/06 15:02:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
}

Hausaufgabenheft:
	addSeite
	addCover
	removeCover
	changeCover(NewCover)
	Cover:
		changeCover(CoverContent)
		addSticker
		InfoSticker:
			addSticker
			
	Seiten:
		changeSeite

class PhoneBook {
	Contact contacts[8];
}

Contact.cpp
private:
firstName

public:
setFirstName(name) {
	if (name.hasNumbers)
		return;
	if (name.hasSpecialChars)
		return;
	name = firstName;
}
getFirstName() -> firsName



main:
Contact lars;
lars.setFirstName(
	"Lars"
)
std::cout << lars.getFirstName()

#endif
