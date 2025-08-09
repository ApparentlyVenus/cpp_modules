/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:57:52 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:13:57 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& otherAnimal) : type(otherAnimal.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& otherAnimal)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &otherAnimal) {
        type = otherAnimal.type;
    }
    return (*this);
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound..." << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
