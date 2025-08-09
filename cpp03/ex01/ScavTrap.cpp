/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:08:55 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 20:21:24 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap: Called Default Constructor" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap: Called Constructor with name" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& otherScavTrap) : ClapTrap(otherScavTrap)
{
    std::cout << "ScavTrap: Called Copy Constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap: Called Copy Assignment Operator" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Called Destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot attack as it has no hitpoints remaining!" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot attack as it has no energy points remaining!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " uses \"SCAV ATTACK\" on " << target 
              << " causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout   << "ScavTrap " << this->name << " is now in Gate keeper mode!"
                << std::endl;
}