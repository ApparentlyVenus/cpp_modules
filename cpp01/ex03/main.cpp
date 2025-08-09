/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:00:07 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 21:40:17 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"

int main()
{
	{
	std::cout << "-----HUMAN A START-----" << std::endl;
	
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	
	std::cout << "Current weapon " << bob.getWeapon() << std::endl;
	bob.attack();
	
	club.setType("some other type of club");
	std::cout << "Current weapon " << bob.getWeapon() << std::endl;
	bob.attack();
	
	std::cout << "-----HUMAN A END-----" << std::endl;
	}
	{	
	std::cout << "-----HUMAN B START-----" << std::endl;

	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	
	std::cout << "Current weapon " << jim.getWeapon() << std::endl;
	jim.attack();

	jim.setWeapon(club);
	std::cout << "Current weapon " << jim.getWeapon() << std::endl;
	jim.attack();
	
	club.setType("some other type of club");
	std::cout << "Current weapon " << jim.getWeapon() << std::endl;
	jim.attack();

	std::cout << "-----HUMAN B END-----" << std::endl;

	}
	
	return (0);
}

