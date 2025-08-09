/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:27:42 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 03:17:06 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:

        AMateria    *templates[4];
        
    public:

        MateriaSource();
        MateriaSource(const MateriaSource& otherMateriaSource);
        MateriaSource& operator=(const MateriaSource& otherMateriaSource);
        virtual ~MateriaSource();
        virtual AMateria*   createMateria(std::string const & type);
        virtual void        learnMateria(AMateria* m);
        
};

#endif