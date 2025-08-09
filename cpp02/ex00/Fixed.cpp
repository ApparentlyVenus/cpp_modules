/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:06:00 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 13:25:51 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8; 

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed& otherFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = otherFixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& otherFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherFixed)
		return (*this);
	this->rawBits = otherFixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void	Fixed::setRawBits(int const rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}