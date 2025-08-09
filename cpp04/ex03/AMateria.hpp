/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 01:27:40 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 03:25:08 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
    protected:

        std::string type;
    
    public:

        AMateria(const std::string &type);
        AMateria(const AMateria& otherAMateria);
        AMateria& operator=(const AMateria& otherAMateria);
        virtual ~AMateria();
        const std::string& getType(void) const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif