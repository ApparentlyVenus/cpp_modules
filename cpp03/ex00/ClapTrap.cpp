/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:27:17 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 20:02:48 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap: Called Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap: Called Constructor with name" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Called Destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& otherClapTrap)
    :   name(otherClapTrap.name), hitPoints(otherClapTrap.hitPoints),
        energyPoints(otherClapTrap.energyPoints), attackDamage(otherClapTrap.attackDamage)
{
    std::cout << "ClapTrap: Called Copy Constructor" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
    std::cout << "ClapTrap: Called Copy Assignment Operator" << std::endl;
    if (this == &otherClapTrap)
		return (*this);
	this->name = otherClapTrap.name;
    this->energyPoints = otherClapTrap.energyPoints;
    this->attackDamage = otherClapTrap.attackDamage;
    this->hitPoints = otherClapTrap.hitPoints;
	return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout   << "ClapTrap " << this->name << " cannot attack as it"
                    << " has no hitpoints remaining!" << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout   << "ClapTrap " << this->name << " cannot attack as it"
                    << " has no energy points remaining!" << std::endl;
        return ;
    }

    std::cout   << "ClapTrap " << this->name << " attacks " << target 
                << " causing "  << this->attackDamage << " points of damage!" 
                << std::endl;
    this->energyPoints--;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout   << "ClapTrap " << this->name << " cannot repair as it"
                    << " has no hitpoints remaining!" << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout   << "ClapTrap " << this->name << " cannot repair as it"
                    << " has no energy points remaining!" << std::endl;
        return ;
    }
    std::cout   << "ClapTrap " << this->name << " repaired " << amount << " of hitpoints"
                << std::endl;
    this->hitPoints += amount;
    this->energyPoints--;
}

    void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout   << "ClapTrap " << this->name << " cannot take damage as it"
                    << " has no hitpoints remaining!" << std::endl;
        return ;
    }
     std::cout   << "ClapTrap " << this->name << " took " << amount << " of damage"
             << std::endl;
    if (amount >= this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}
