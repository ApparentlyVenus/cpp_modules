/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:55:10 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:22:53 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

#ifndef DEBUG_CONSTRUCTORS
# define DEBUG_CONSTRUCTORS 1
#endif

Cure::Cure() : AMateria("cure")
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure& otherCure) : AMateria(otherCure)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure& Cure::operator=(const Cure& otherCure)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout <<  "Cure Copy Assignment Operator Called" << std::endl;
    if (this != &otherCure)
        AMateria::operator=(otherCure);
    return (*this);
}

Cure::~Cure()
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Cure Destructor Called" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure (*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}