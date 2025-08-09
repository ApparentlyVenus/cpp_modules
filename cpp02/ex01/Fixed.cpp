/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:06:00 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 14:06:57 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}


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

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(floatValue * (1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)rawBits / (1 << fractionalBits));
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const rawBits)
{
	this->rawBits = rawBits;
}