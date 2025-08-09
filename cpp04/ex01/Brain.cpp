/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:29:13 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:35:54 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain& otherBrain)
{
    std::cout << "Copy Brain Constructor Called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = otherBrain.ideas[i];
}

Brain& Brain::operator=(const Brain& otherBrain)
{
    std::cout << "Copy assignment operator for Brain Called" << std::endl;
    if (this != &otherBrain)
    { 
        for (int i = 0; i < 100; i++)
            this->ideas[i] = otherBrain.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}