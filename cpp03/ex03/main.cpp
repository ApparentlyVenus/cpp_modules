/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:26:33 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 23:19:55 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "--- TESTING VIRTUAL INHERITANCE CONSTRUCTOR CHAINING ---" << std::endl;
    
    std::cout << "\n--- Creating DiamondTrap with name ---" << std::endl;
    DiamondTrap diamond1("Sparky");
    
    std::cout << "\n--- Creating DiamondTrap with default constructor ---" << std::endl;
    DiamondTrap diamond2;
    
    std::cout << "\n--- Creating DiamondTrap with copy constructor ---" << std::endl;
    DiamondTrap diamond3(diamond1);
    
    std::cout << "\n--- TESTING NAME SHADOWING ---" << std::endl;
    
    std::cout << "\n--- Testing whoAmI() function ---" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();
    
    std::cout << "\n--- TESTING INHERITED ABILITIES ---" << std::endl;
    
    std::cout << "\n--- Testing ScavTrap's guardGate() ---" << std::endl;
    diamond1.guardGate();
    
    std::cout << "\n--- Testing FragTrap's highFivesGuys() ---" << std::endl;
    diamond1.highFivesGuys();
    
    std::cout << "\n--- TESTING MIXED ATTRIBUTES ---" << std::endl;
    
    std::cout << "\n--- Testing attack (should use ScavTrap's version) ---" << std::endl;
    diamond1.attack("Enemy Robot");
    
    std::cout << "\n--- Testing inherited basic functions ---" << std::endl;
    diamond1.takeDamage(40);
    diamond1.beRepaired(20);
    
    std::cout << "\n--- TESTING ENERGY LIMITS (ScavTrap: 50) ---" << std::endl;
    
    std::cout << "\n--- Testing DiamondTrap energy (should be 50 like ScavTrap) ---" << std::endl;
    for (int i = 1; i <= 52; i++)
    {
        if (i <= 3 || i > 49)
            std::cout << "Action " << i << ": ";
        diamond2.attack("Target");
    }
    
    std::cout << "\n--- TESTING HIT POINTS (FragTrap: 100) ---" << std::endl;
    
    std::cout << "\n--- Testing DiamondTrap hit points (should be 100 like FragTrap) ---" << std::endl;
    diamond3.takeDamage(60);
    diamond3.attack("Still Alive");
    diamond3.takeDamage(50);
    diamond3.attack("Dead Target");
    
    std::cout << "\n--- COMPARING ALL ROBOT TYPES ---" << std::endl;
    
    std::cout << "\n--- Creating one of each type ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("PartyBot");
    DiamondTrap diamond("SuperBot");
    
    std::cout << "\n--- Attack comparison ---" << std::endl;
    clap.attack("Enemy");
    scav.attack("Enemy");
    frag.attack("Enemy");
    diamond.attack("Enemy");
    
    std::cout << "\n--- Special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    diamond.whoAmI();
    
    std::cout << "\n--- TESTING COPY ASSIGNMENT ---" << std::endl;
    
    std::cout << "\n--- Testing copy assignment operator ---" << std::endl;
    DiamondTrap diamond4;
    diamond4 = diamond1;
    diamond4.whoAmI();
    
    std::cout << "\n--- DESTRUCTORS WILL BE CALLED ---" << std::endl;
    std::cout << "Watch the destructor order (should be reverse of construction):" << std::endl;
    
    return (0);
}
