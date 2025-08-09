/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:42:22 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 01:44:56 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    
        Ice();
        Ice(const Ice& otherIce);
        Ice& operator=(const Ice& otherIce);
        ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif