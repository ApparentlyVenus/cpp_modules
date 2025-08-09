/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:50:42 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 21:24:22 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include<iostream>
# include<string>

class Weapon
{
	private:
	
		std::string	type;
 
	public:
	
		Weapon(std::string weapon);
		~Weapon();

		void			setType(std::string type);
		const std::string&	getType();
};

#endif
