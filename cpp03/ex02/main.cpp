/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:26:33 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 20:48:36 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- TESTING CONSTRUCTOR CHAINING ---" << std::endl;
    
    std::cout << "\n--- Creating FragTrap with default constructor ---" << std::endl;
    FragTrap Frag1;
    
    std::cout << "\n--- Creating FragTrap with name ---" << std::endl;
    FragTrap Frag2("Guardian");
    
    std::cout << "\n--- Creating FragTrap with copy constructor ---" << std::endl;
    FragTrap Frag3(Frag2);
    
    std::cout << "\n--- TESTING BASIC FUNCTIONALITY ---" << std::endl;
    
    std::cout << "\n--- Testing inherited functions ---" << std::endl;
    Frag2.attack("Enemy Robot");
    Frag2.takeDamage(30);
    Frag2.beRepaired(15);
    
    std::cout << "\n--- Testing FragTrap special ability ---" << std::endl;
    Frag2.highFivesGuys();
    
    std::cout << "\n--- TESTING FRAGTRAP VS CLAPTRAP ---" << std::endl;
    
    std::cout << "\n--- Creating ClapTrap for comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    
    std::cout << "\n--- ClapTrap attack vs FragTrap attack ---" << std::endl;
    clap.attack("Target");
    Frag2.attack("Target");
    
    std::cout << "\n--- TESTING ENERGY DEPLETION ---" << std::endl;
    
    std::cout << "\n--- Testing FragTrap energy limits ---" << std::endl;
    for (int i = 1; i <= 32; i++)
    {
        if (i <= 3 || i > 30)
            std::cout << "Action " << i << ": ";
        Frag1.attack("Enemy");
    }
    
    std::cout << "\n--- TESTING DAMAGE RESISTANCE ---" << std::endl;
    
    std::cout << "\n--- Testing FragTrap hit points ---" << std::endl;
    Frag3.takeDamage(50);
    Frag3.attack("Still Alive Target");
    Frag3.takeDamage(60);
    Frag3.attack("Dead Target");
    
    std::cout << "\n--- DESTRUCTORS WILL BE CALLED ---" << std::endl;
    return (0);
}

