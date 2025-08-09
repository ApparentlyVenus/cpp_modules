/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:41:55 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:21:11 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#ifndef DEBUG_CONSTRUCTORS
# define DEBUG_CONSTRUCTORS 1
#endif

AMateria::AMateria(const std::string& type) : type(type)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "AMateria Type Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria& otherAMateria)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "AMateria Copy Constructor Called" << std::endl;
    this->type = otherAMateria.getType();
}

AMateria& AMateria::operator=(const AMateria &otherAMateria)
{    
    if (DEBUG_CONSTRUCTORS)
        std::cout << "AMateria Copy Assignment Operator Called" << std::endl;
    (void)otherAMateria;
    return (*this);
}

AMateria::~AMateria()
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "AMateria Destructor Called" << std::endl;
}

const std::string& AMateria::getType(void) const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}