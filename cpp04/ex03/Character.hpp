/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:15:49 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:28:32 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
    private:

        std::string name;
        AMateria    *inventory[4];
        
    public:

        Character(const std::string& name);
        Character(const Character& otherCharacter);
        Character&  operator=(const Character& otherCharacter);
        virtual     ~Character();
        virtual void        equip(AMateria* m);
        virtual void        unequip(int index);
        virtual void        use(int index, ICharacter&);
        virtual const std::string& getName() const;
};

#endif 