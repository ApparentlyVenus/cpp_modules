/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:06:00 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 15:17:04 by odana            ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->rawBits > other.rawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->rawBits <= other.rawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->rawBits >= other.rawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->rawBits == other.rawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->rawBits != other.rawBits);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
    result.rawBits = this->rawBits + other.rawBits;
    return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
    result.rawBits = this->rawBits - other.rawBits;
    return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.rawBits = (this->rawBits * other.rawBits) >> fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.rawBits = (this->rawBits << fractionalBits) / other.rawBits;
	return (result);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.rawBits > f2.rawBits)
		return (f2);
	return (f1);
}

Fixed& Fixed::operator++()
{
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->rawBits++;
	return (temp);
}

Fixed& Fixed::operator--()
{
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->rawBits--;
	return (temp);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.rawBits > f2.rawBits)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.rawBits > f2.rawBits)
		return (f2);
	return (f1);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.rawBits > f2.rawBits)
		return (f1);
	return (f2);
}

