/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:45:46 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:17:45 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include<string>
# include<iostream>

class Animal
{
    protected:
        
        std::string type;

	public:

		Animal();
		Animal(const Animal& otherAnimal);
		Animal&	operator=(const Animal& otherAnimal);
		virtual ~Animal();
		
		virtual void	makeSound() const;
		std::string 	getType() const;
};

#endif