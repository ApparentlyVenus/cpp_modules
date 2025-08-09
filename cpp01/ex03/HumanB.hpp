/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:53:29 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 21:41:25 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		
		std::string	name;
		Weapon*		weapon;
		
	public:
	
		HumanB(std::string name);
		~HumanB();
		
		const std::string	getWeapon() const;
		void			setWeapon(Weapon& weapon);
		void			attack() const;
};

#endif