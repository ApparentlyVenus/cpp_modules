/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:02:18 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 13:11:21 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class	PhoneBook
{
	private:
	
		Contact contacts[8];
		int		index;
		int		totalContacts;
		
	public:
	
		PhoneBook();
		~PhoneBook();
		
		int			getTotalContacts();
		void		addContact();
		void		searchContact() const;
		void		displayContact(int i) const;
		std::string	formatField(const std::string& field) const;
		
};

#endif