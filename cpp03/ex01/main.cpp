/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:26:33 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 20:25:09 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- TESTING CONSTRUCTOR CHAINING ---" << std::endl;
    
    std::cout << "\n--- Creating ScavTrap with default constructor ---" << std::endl;
    ScavTrap scav1;
    
    std::cout << "\n--- Creating ScavTrap with name ---" << std::endl;
    ScavTrap scav2("Guardian");
    
    std::cout << "\n--- Creating ScavTrap with copy constructor ---" << std::endl;
    ScavTrap scav3(scav2);
    
    std::cout << "\n--- TESTING BASIC FUNCTIONALITY ---" << std::endl;
    
    std::cout << "\n--- Testing inherited functions ---" << std::endl;
    scav2.attack("Enemy Robot");
    scav2.takeDamage(30);
    scav2.beRepaired(15);
    
    std::cout << "\n--- Testing ScavTrap special ability ---" << std::endl;
    scav2.guardGate();
    
    std::cout << "\n--- TESTING SCAVTRAP VS CLAPTRAP ---" << std::endl;
    
    std::cout << "\n--- Creating ClapTrap for comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    
    std::cout << "\n--- ClapTrap attack vs ScavTrap attack ---" << std::endl;
    clap.attack("Target");
    scav2.attack("Target");
    
    std::cout << "\n--- TESTING ENERGY DEPLETION ---" << std::endl;
    
    std::cout << "\n--- Testing ScavTrap energy limits ---" << std::endl;
    for (int i = 1; i <= 52; i++)
    {
        if (i <= 3 || i > 50)
            std::cout << "Action " << i << ": ";
        scav1.attack("Enemy");
    }
    
    std::cout << "\n--- TESTING DAMAGE RESISTANCE ---" << std::endl;
    
    std::cout << "\n--- Testing ScavTrap hit points ---" << std::endl;
    scav3.takeDamage(50);
    scav3.attack("Still Alive Target");
    scav3.takeDamage(60);
    scav3.attack("Dead Target");
    
    std::cout << "\n--- DESTRUCTORS WILL BE CALLED ---" << std::endl;
    return (0);
}

