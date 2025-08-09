/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:53:29 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 21:34:35 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
		void				setWeapon(Weapon& weapon);
		const std::string&	getWeapon() const;
		void				attack() const;
};

#endif