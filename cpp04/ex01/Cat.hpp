/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:49:12 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:39:16 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:

        Brain *brain;

    public:

        Cat();
        Cat(const Cat& otherCat);
        Cat& operator=(const Cat& otherCat);
        virtual ~Cat();
    
        virtual void    makeSound() const;
};

#endif