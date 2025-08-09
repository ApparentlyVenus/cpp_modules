/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:27:18 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 08:58:08 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>


class	Contact
{
	private:
	
		std::string 	firstName;
		std::string 	lastName;
		std::string		nickName;
		std::string 	darkestSecret;
		std::string		number;
		
	public:
	
		Contact();
		~Contact();

		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickName(const std::string& nickName);
		void		setDarkestSecret(const std::string& darkestSecret);
		void		setNumber(const std::string& number);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string getNickName() const;
		std::string	getDarkestSecret() const;
		std::string	getNumber() const;
};

#endif