/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:55:12 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 13:12:41 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->totalContacts = 0;
}

PhoneBook::~PhoneBook() {}

int		PhoneBook::getTotalContacts()
{
	return (this->totalContacts);
}

void	PhoneBook::addContact()
{
	std::string input;
	
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, input))
		return ;
	while (input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl << "Enter first name: ";
	if (!std::getline(std::cin, input))
		return ;
	}
	this->contacts[this->index].setFirstName(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl << "Enter last name: ";
	if (!std::getline(std::cin, input))
		return ;
	}
	this->contacts[this->index].setLastName(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl << "Enter nickname: ";
	if (!std::getline(std::cin, input))
		return ;
	}
	this->contacts[this->index].setNickName(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl << "Enter darkest secret: ";
	if (!std::getline(std::cin, input))
		return ;
	}
	this->contacts[this->index].setDarkestSecret(input);
	std::cout << "Enter number: ";
	std::getline(std::cin, input);
		while (input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl << "Enter number: ";
	if (!std::getline(std::cin, input))
		return ;
	}
	this->contacts[this->index].setNumber(input);
	this->index = (this->index + 1) % 8;
	if (this->totalContacts < 8)
		totalContacts++;
}

std::string	PhoneBook::formatField(const std::string& field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	PhoneBook::searchContact() const
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|"; 
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->totalContacts; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right <<
            formatField(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right <<
            formatField(this->contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right <<
            formatField(this->contacts[i].getNickName()) << "|";
        std::cout << std::endl;
	}
}

void	PhoneBook::displayContact(int i) const
{
	if (i < 0 || i >= this->totalContacts)
	{
		std::cout << "Invalid Index!" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].getNickName() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i].getDarkestSecret() << std::endl;
	std::cout << "Number: " << this->contacts[i].getNumber() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

