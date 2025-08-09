/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:08:53 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:17:56 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include<string>
# include<iostream>

class WrongAnimal
{
    protected:
        
        std::string type;

	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal& otherWrongAnimal);
		WrongAnimal&	operator=(const WrongAnimal& otherWrongAnimal);
		virtual ~WrongAnimal();
		
		void	    makeSound() const;
		std::string getType() const;
};

#endif