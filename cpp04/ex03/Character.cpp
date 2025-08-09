/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:14:25 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:21:55 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

#ifndef DEBUG_CONSTRUCTORS
# define DEBUG_CONSTRUCTORS 1
#endif

Character::Character(const std::string& name) : name(name)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Character Name Constructor Called" << std::endl;
    for (int i = 0; i < 4; i++) 
        inventory[i] = NULL;
}

Character::Character(const Character& otherCharacter) : name(otherCharacter.getName())
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Character Copy Constructor Called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (otherCharacter.inventory[i] != NULL)
            inventory[i] = otherCharacter.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Character Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        name = other.name;

        for (int i = 0; i < 4; i++)
        {
            if (inventory[i] != NULL)
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return (*this);
}   

Character::~Character()
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Character Destructor Called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

const std::string& Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << name << "'s inventory is full! Cannot equip " << m->getType() << std::endl;
    delete m;
}


void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot " << idx << std::endl;
        return;
    }
    if (inventory[idx] == NULL) {
        std::cout << "Slot " << idx << " is already empty" << std::endl;
        return;
    }    
    std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot " << idx << std::endl;
        return;
    }
    if (inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }    
    inventory[idx]->use(target);
}

