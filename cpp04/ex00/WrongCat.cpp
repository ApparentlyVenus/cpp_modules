/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:08:56 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:11:39 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& otherWrongCat) : WrongAnimal(otherWrongCat)
{
    type = "WrongCat";
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& otherWrongCat)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &otherWrongCat)
    {
        WrongAnimal::operator=(otherWrongCat);
        type = "WrongCat";
    }
    return (*this);
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "meow meow 3ATINE AKEL!!" << std::endl;
}