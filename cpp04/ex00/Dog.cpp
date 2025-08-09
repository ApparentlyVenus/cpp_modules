/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:06:53 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:12:09 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& otherDog) : Animal(otherDog)
{
    type = "Dog";
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& otherDog)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &otherDog)
    {
        Animal::operator=(otherDog);
        type = "Dog";
    }
    return (*this);
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "3AW 3AW JEYE EKLAK!!" << std::endl;
}