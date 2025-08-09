/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:57:52 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:59:08 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& otherAAnimal) : type(otherAAnimal.type)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& otherAAnimal)
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &otherAAnimal) {
        type = otherAAnimal.type;
    }
    return (*this);
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}
