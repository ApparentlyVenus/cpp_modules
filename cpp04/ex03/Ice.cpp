/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:02:56 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:23:51 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

#ifndef DEBUG_CONSTRUCTORS
# define DEBUG_CONSTRUCTORS 1
#endif

Ice::Ice() : AMateria("ice")
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice& otherIce) : AMateria(otherIce)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice& Ice::operator=(const Ice& otherIce)
{
    if (DEBUG_CONSTRUCTORS)
        std::cout <<  "Ice Copy Assignment Operator Called" << std::endl;
    if (this != &otherIce)
        AMateria::operator=(otherIce);
    return (*this);
}

Ice::~Ice()
{
    if (DEBUG_CONSTRUCTORS)
        std::cout << "Ice Destructor Called" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice (*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}