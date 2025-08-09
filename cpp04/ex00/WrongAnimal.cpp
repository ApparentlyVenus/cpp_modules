/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:08:48 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:13:40 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& otherWrongAnimal)
    : type(otherWrongAnimal.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& otherWrongAnimal)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &otherWrongAnimal) {
        type = otherWrongAnimal.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic WrongAnimal sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}