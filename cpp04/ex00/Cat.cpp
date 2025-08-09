/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:59:51 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:11:56 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& otherCat) : Animal(otherCat)
{
    type = "Cat";
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& otherCat)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &otherCat)
    {
        Animal::operator=(otherCat);
        type = "Cat";
    }
    return (*this);
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "meow meow 3ATINE AKEL!!" << std::endl;
}

