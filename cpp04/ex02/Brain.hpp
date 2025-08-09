/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:24:53 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:39:01 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    private:

        std::string ideas[100];
    
    public:

        Brain();
        Brain(const Brain& otherBrain);
        Brain& operator=(const Brain& otherBrain);
        ~Brain();
        
};

#endif