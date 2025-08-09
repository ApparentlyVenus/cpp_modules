/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:27:21 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 04:15:10 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{    
    std::cout << "\n--- Test 1: Subject Required Test ---" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    
    std::cout << "\n--- Test 2: Factory Pattern Testing ---" << std::endl;
    {
        std::cout << "\nCreating MateriaSource factory:" << std::endl;
        MateriaSource* factory = new MateriaSource();
        
        std::cout << "\nTeaching factory different materia types:" << std::endl;
        factory->learnMateria(new Ice());
        factory->learnMateria(new Cure());
        factory->learnMateria(new Ice());
        
        std::cout << "\nTesting factory creation:" << std::endl;
        AMateria* ice1 = factory->createMateria("ice");
        AMateria* cure1 = factory->createMateria("cure");
        AMateria* fire = factory->createMateria("fire");
        
        std::cout << "\nCreated materias:" << std::endl;
        if (ice1) std::cout << "Successfully created: " << ice1->getType() << std::endl;
        if (cure1) std::cout << "Successfully created: " << cure1->getType() << std::endl;
        if (!fire) std::cout << "Failed to create fire (as expected)" << std::endl;
        
        delete ice1;
        delete cure1;
        delete factory;
    }
    
    std::cout << "\n--- Test 3: Character Inventory Management ---" << std::endl;
    {
        Character* wizard = new Character("Gandalf");
        MateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        std::cout << "\nEquipping materias:" << std::endl;
        AMateria* ice1 = src->createMateria("ice");
        AMateria* cure1 = src->createMateria("cure");
        AMateria* ice2 = src->createMateria("ice");
        AMateria* cure2 = src->createMateria("cure");
        
        wizard->equip(ice1);
        wizard->equip(cure1);
        wizard->equip(ice2);
        wizard->equip(cure2);
        
        std::cout << "\nTrying to overfill inventory:" << std::endl;
        wizard->equip(src->createMateria("ice"));
        
        std::cout << "\nTesting unequip:" << std::endl;
        
        AMateria* materiaOnFloor = cure1;
        wizard->unequip(1);
        
        wizard->unequip(5);
        wizard->unequip(1);
        
        std::cout << "\nEquipping in freed slot:" << std::endl;
        wizard->equip(src->createMateria("cure"));
        
        delete materiaOnFloor;
        
        delete wizard;
        delete src;
    }
    
    std::cout << "\n--- Test 4: Character Combat System ---" << std::endl;
    {
        Character* mage = new Character("Merlin");
        Character* target = new Character("Enemy");
        
        MateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        mage->equip(src->createMateria("ice"));
        mage->equip(src->createMateria("cure"));
        
        std::cout << "\nCombat simulation:" << std::endl;
        mage->use(0, *target);
        mage->use(1, *target);
        mage->use(2, *target);
        mage->use(-1, *target);
        
        delete mage;
        delete target;
        delete src;
    }
    
    std::cout << "\n--- Test 5: Deep Copy Testing ---" << std::endl;
    {
        std::cout << "\nTesting Character deep copy:" << std::endl;
        Character* original = new Character("Original");
        MateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        original->equip(src->createMateria("ice"));
        
        std::cout << "\nCopy constructor test:" << std::endl;
        Character* copy = new Character(*original);
        
        std::cout << "\nAssignment operator test:" << std::endl;
        Character* assigned = new Character("Assigned");
        *assigned = *original;
        
        std::cout << "\nTesting independence (each should have separate inventory):" << std::endl;
        Character* dummy = new Character("Dummy");
        
        original->use(0, *dummy);
        copy->use(0, *dummy);
        assigned->use(0, *dummy);
        
        delete original;
        delete copy;
        delete assigned;
        delete dummy;
        delete src;
    }
    
    std::cout << "\n--- Test 6: MateriaSource Deep Copy ---" << std::endl;
    {
        std::cout << "\nCreating and learning materias:" << std::endl;
        MateriaSource* original = new MateriaSource();
        original->learnMateria(new Ice());
        original->learnMateria(new Cure());
        
        std::cout << "\nCopy constructor:" << std::endl;
        MateriaSource* copy = new MateriaSource(*original);
        
        std::cout << "\nTesting both sources can create independently:" << std::endl;
        AMateria* ice1 = original->createMateria("ice");
        AMateria* ice2 = copy->createMateria("ice");
        
        if (ice1 && ice2) {
            std::cout << "Both sources successfully created ice" << std::endl;
            delete ice1;
            delete ice2;
        }
        
        delete original;
        delete copy;
    }
    
    std::cout << "\n--- Test 7: Memory Management Test ---" << std::endl;
    {
        std::cout << "\nCreating and destroying multiple objects:" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            MateriaSource* src = new MateriaSource();
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            
            Character* char1 = new Character("Temp1");
            Character* char2 = new Character("Temp2");
            
            char1->equip(src->createMateria("ice"));
            char2->equip(src->createMateria("cure"));
            
            char1->use(0, *char2);
            
            delete char1;
            delete char2;
            delete src;
        }
        std::cout << "Memory management test completed" << std::endl;
    }
    
    std::cout << "\n--- Test 8: Edge Cases ---" << std::endl;
    {
        std::cout << "\nTesting edge cases:" << std::endl;
        Character* char1 = new Character("EdgeTester");
        MateriaSource* src = new MateriaSource();
        
        char1->equip(NULL);
        
        src->learnMateria(NULL);
        
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        
        delete char1;
        delete src;
    }
    std::cout << "\n=== All Tests Completed Successfully! ===" << std::endl;
    return (0);
}