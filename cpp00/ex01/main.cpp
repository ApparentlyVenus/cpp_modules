/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:32:13 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 13:13:38 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    int         index;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            return (1);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
        {
			if (phoneBook.getTotalContacts() == 0)
			{
				std::cout << "Empty Contact Book!" << std::endl;
				continue ;
			}
            phoneBook.searchContact();
            std::cout << "Enter index: ";
            if (std::cin >> index)
			{
                std::cin.ignore();
                if (index >= 0 && index < 8)
                    phoneBook.displayContact(index);
                else
            		std::cout << "Invalid index." << std::endl;
			}
			else
				return (1);
        }
        else if (command == "EXIT")
        {
            std::cout << "You slowly close the phonebook... * POOF *";
            break;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}
