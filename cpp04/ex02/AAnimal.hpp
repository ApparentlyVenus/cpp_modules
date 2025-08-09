/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:45:46 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:59:28 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include<string>
# include<iostream>

class AAnimal
{
    protected:
        
        std::string type;

	public:

		AAnimal();
		AAnimal(const AAnimal& otherAAnimal);
		AAnimal&	operator=(const AAnimal& otherAAnimal);
		virtual ~AAnimal();
		
		virtual void	makeSound() const = 0;
		std::string 	getType() const;
};

#endif