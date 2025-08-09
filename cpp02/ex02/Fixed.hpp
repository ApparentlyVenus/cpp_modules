/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:52:41 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 15:15:18 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	
		int					rawBits;
		static const int	fractionalBits;
	
	public:

		Fixed();
		Fixed(const Fixed& otherFixed);
		Fixed& operator=(const Fixed& otherFixed);
		~Fixed();
		
		Fixed(const int intValue);
		Fixed(const float floatValue);
		
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;

		Fixed	operator++(int);
		Fixed&	operator++();
		Fixed	operator--(int);
		Fixed&	operator--();
		
		static			Fixed&	min(Fixed& f1, Fixed& f2);
		static 			Fixed&	max(Fixed& f1, Fixed& f2);
		static const	Fixed&	min(const Fixed& f1, const Fixed& f2);
		static const	Fixed&	max(const Fixed& f1, const Fixed& f2);
		
		float	toFloat(void) const;
		int		toInt(void)	const;
		int 	getRawBits(void) const;
    	void 	setRawBits(int const rawBits);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif