/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:08:59 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:10:34 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:

        WrongCat();
        WrongCat(const WrongCat& otherWrongCat);
        WrongCat& operator=(const WrongCat& otherWrongCat);
        virtual ~WrongCat();
    
        void    makeSound() const;
};

#endif