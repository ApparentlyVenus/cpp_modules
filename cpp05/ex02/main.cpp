/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 03:21:47 by odana             #+#    #+#             */
/*   Updated: 2025/08/21 03:23:15 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n--- Test 1: Creating Bureaucrats ---" << std::endl;
    try {
        Bureaucrat lowLevel("Intern THE ORIGINAL STARWALKER", 150);
        Bureaucrat midLevel("Manager ???", 50);
        Bureaucrat highLevel("Director Yitany", 5);
        Bureaucrat thePresident("President ODana", 1);

        std::cout << lowLevel << std::endl;
        std::cout << midLevel << std::endl;
        std::cout << highLevel << std::endl;
        std::cout << thePresident << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: ShrubberyCreationForm ---" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        Bureaucrat gardener("Gardener", 140);
        
        std::cout << shrub << std::endl;
        std::cout << gardener << std::endl;
        
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << "Check for 'garden_shrubbery' file in current directory!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: RobotomyRequestForm ---" << std::endl;
    try {
        RobotomyRequestForm robot("Bender");
        Bureaucrat engineer("Engineer", 40);
        
        std::cout << robot << std::endl;
        engineer.signForm(robot);
        
        std::cout << "\nAttempt 1:" << std::endl;
        engineer.executeForm(robot);
        
        std::cout << "\nAttempt 2:" << std::endl;
        engineer.executeForm(robot);
        
        std::cout << "\nAttempt 3:" << std::endl;
        engineer.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: PresidentialPardonForm ---" << std::endl;
    try {
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat president("President", 1);
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Permission Failures ---" << std::endl;
    try {
        PresidentialPardonForm vipPardon("Arthur Dent");
        Bureaucrat lowGuy("Low Guy", 100);
        
        std::cout << "\nTrying to sign presidential pardon with low-grade bureaucrat:" << std::endl;
        lowGuy.signForm(vipPardon);
        
        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        Bureaucrat boss("Boss", 1);
        boss.executeForm(vipPardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 6: Grade Boundary Testing ---" << std::endl;
    try {
        ShrubberyCreationForm shrub2("office");
        
        Bureaucrat almostGood("Almost Good", 146);
        Bureaucrat justGood("Just Good", 145);
        Bureaucrat cantExecute("Can't Execute", 138);
        Bureaucrat canExecute("Can Execute", 137);
        
        std::cout << "\nTesting sign boundary (need 145):" << std::endl;
        almostGood.signForm(shrub2);
        justGood.signForm(shrub2);
        
        std::cout << "\nTesting execute boundary (need 137):" << std::endl;
        cantExecute.executeForm(shrub2);
        canExecute.executeForm(shrub2);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 7: One Bureaucrat, All Forms ---" << std::endl;
    try {
        Bureaucrat superBoss("Super Boss", 1);
        
        ShrubberyCreationForm shrub3("headquarters");
        RobotomyRequestForm robot2("R2D2");
        PresidentialPardonForm pardon2("Luke Skywalker");
        
        std::cout << "\nSigning all forms:" << std::endl;
        superBoss.signForm(shrub3);
        superBoss.signForm(robot2);
        superBoss.signForm(pardon2);
        
        std::cout << "\nExecuting all forms:" << std::endl;
        superBoss.executeForm(shrub3);
        superBoss.executeForm(robot2);
        superBoss.executeForm(pardon2);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}