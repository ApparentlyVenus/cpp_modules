/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:52:06 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 01:00:02 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    private:

        Brain *brain;
    
    public:

        Dog();
        Dog(const Dog& otherDog);
        Dog& operator=(const Dog& otherDog);
        ~Dog();
    
        virtual void    makeSound() const;
};

#endif