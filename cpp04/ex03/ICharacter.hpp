/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:09:46 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 02:35:38 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

class ICharacter
{
    public:
    
        virtual             ~ICharacter() {}
        virtual void        equip(AMateria* m) = 0;
        virtual void        unequip(int index) = 0;
        virtual void        use(int index, ICharacter& target) = 0;
        virtual const std::string& getName() const = 0;
};

#endif