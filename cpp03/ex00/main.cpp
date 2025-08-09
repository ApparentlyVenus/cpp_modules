/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:26:33 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 20:00:09 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot1;
    ClapTrap robot2("R2D2");
    ClapTrap robot3(robot2);
    
    std::cout << std::endl;
    
    robot2.attack("Enemy");
    robot2.takeDamage(5);
    robot2.beRepaired(3);
    
    std::cout << std::endl;
    
    for (int i = 0; i < 11; i++)
        robot2.attack("Target");
    
    std::cout << std::endl;

    robot1.takeDamage(15);
    robot1.attack("Enemy");
    robot1.beRepaired(5);
    
    return (0);
}
