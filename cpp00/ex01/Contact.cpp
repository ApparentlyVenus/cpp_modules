/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:07:12 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 01:37:24 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->darkestSecret = "";
	this->number = "";
}

Contact::~Contact() {}

void	Contact::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	this->nickName = nickName;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void	Contact::setNumber(const std::string& number)
{
	this->number = number;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickName() const
{
	return (this->nickName);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

std::string Contact::getNumber() const
{
	return (this->number);
}