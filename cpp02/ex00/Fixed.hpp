/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:52:41 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 13:18:49 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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

		int getRawBits(void) const;
    	void setRawBits(int const rawBits);
};


#endif