/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:24:38 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 02:37:34 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
    public:

        virtual             ~IMateriaSource() {}
        virtual AMateria*   createMateria(std::string const & type) = 0;
        virtual void        learnMateria(AMateria* m) = 0;
};

#endif