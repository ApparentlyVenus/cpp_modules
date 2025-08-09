/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:46:21 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:52:32 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "--- Brain Management ---" << std::endl;
    
    std::cout << "\n--- Test 1: Basic Polymorphic Deletion ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nMaking sounds:" << std::endl;
    j->makeSound();
    i->makeSound();
    
    std::cout << "\nDeleting animals (should not create leaks):" << std::endl;
    delete j;
    delete i;
    
    std::cout << "\n--- Test 2: Array of Animals ---" << std::endl;
    const int arraySize = 6;
    Animal* animals[arraySize];
    
    std::cout << "\nCreating array - First half Dogs, second half Cats:" << std::endl;
    
    for (int i = 0; i < arraySize / 2; i++)
    {
        std::cout << "Creating Dog " << i << ":" << std::endl;
        animals[i] = new Dog();
    }
    
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        std::cout << "Creating Cat " << (i - arraySize/2) << ":" << std::endl;
        animals[i] = new Cat();
    }
    
    std::cout << "\nTesting polymorphic behavior:" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\nDeleting all animals as Animals (polymorphic deletion):" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Deleting animal " << i << " (" << animals[i]->getType() << "):" << std::endl;
        delete animals[i];
    }
    
    std::cout << "\n--- Test 3: Deep Copy Testing ---" << std::endl;
    
    std::cout << "\nCreating original Dog:" << std::endl;
    Dog originalDog;
    
    std::cout << "\nCopy constructor test:" << std::endl;
    Dog copiedDog(originalDog);
    
    std::cout << "\nAssignment operator test:" << std::endl;
    Dog assignedDog;
    assignedDog = originalDog;
    
    std::cout << "\nAll dogs should have different Brain addresses:" << std::endl;
    
    std::cout << "\nTesting Cat deep copy:" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;
    
    std::cout << "\n--- Test 4: Stack Objects Destruction Order ---" << std::endl;
    {
        std::cout << "Creating stack objects in scope:" << std::endl;
        Dog stackDog;
        Cat stackCat;
        std::cout << "Leaving scope - destructors should be called in reverse order:" << std::endl;
    }
    
    std::cout << "\n--- End of Tests ---" << std::endl;
    
    return (0);
}