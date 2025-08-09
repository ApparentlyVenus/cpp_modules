/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:42:20 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 01:45:47 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    
        Cure();
        Cure(const Cure& otherCure);
        Cure& operator=(const Cure& otherCure);
        ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif