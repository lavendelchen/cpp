/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:32:16 by shaas             #+#    #+#             */
/*   Updated: 2022/07/09 19:31:13 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		short	_numOfContacts;
		short	_newContactPlace;
		void	printAllContacts(void);
		void	printContactInfo(int index);

	public:
		PhoneBook(void) { _numOfContacts = 0; _newContactPlace = 0; }
		void addContact(void);
		void searchContact(void);
} ;

#endif