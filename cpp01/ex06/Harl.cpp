/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:53:35 by odana             #+#    #+#             */
/*   Updated: 2025/08/07 23:38:28 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
	std::cout	<< "[ DEBUG ]" << std::endl;
	std::cout	<< "I love having extra bacon for"
				<< " my 7XL-double-cheese-triple-pickle-specialketchup"
				<< " burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
	std::cout	<< "[ INFO ]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon costs more money"
				<< " You didn’t put enough bacon in my burger!"
				<< " If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
	std::cout	<< "[ WARNING ]" << std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free."
				<< " I’ve been coming for years,"
				<< " whereas you started working here just last month." << std::endl;
}

void    Harl::error(void)
{
	std::cout	<< "[ ERROR ]" << std::endl;
	std::cout	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Level	Harl::stringToLevel(std::string strLevel)
{	
	if (strLevel == "DEBUG")
		return (DEBUG);
	if (strLevel == "INFO")
		return (INFO);
	if (strLevel == "WARNING")
		return (WARNING);
	if (strLevel == "ERROR")
		return (ERROR);
	return (NOVAL);
}

void	Harl::complain(std::string strLevel)
{
	Level level = stringToLevel(strLevel);
	
	void (Harl::*f[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	switch (level)
	{
		case DEBUG: (this->*f[DEBUG])();
		case INFO: (this->*f[INFO])();
		case WARNING: (this->*f[WARNING])();
		case ERROR: (this->*f[ERROR])();
			break;
		default: std::cout << "[ I'M STILL GOING TO COMPLAIN HAHAHAHAHAHAHAHA ]" << std::endl; break;
	}
}