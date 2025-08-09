/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/08/09 00:17:06 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Testing Polymorphism with Virtual Functions ---" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    std::cout << "meta->getType(): " << meta->getType() << std::endl;
    
    std::cout << "\nSounds (should show polymorphism):" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\nDeleting animals:" << std::endl;
    delete j;
    delete i;
    delete meta;
    
    std::cout << "\n--- Testing Wrong Animals (No Virtual) ---" << std::endl;
    
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrong_cat->getType(): " << wrong_cat->getType() << std::endl;
    std::cout << "wrong_meta->getType(): " << wrong_meta->getType() << std::endl;
    
    std::cout << "\nSounds (should NOT show polymorphism):" << std::endl;
    wrong_cat->makeSound();
    wrong_meta->makeSound();
    
    std::cout << "\nDeleting wrong animals:" << std::endl;
    delete wrong_cat;
    delete wrong_meta;
    
    std::cout << "\n--- Additional Tests ---" << std::endl;
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    
    std::cout << "\nTesting sounds with stack objects:" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;
    
    Animal* ptr_animal = &animal;
    Animal* ptr_dog = &dog;
    Animal* ptr_cat = &cat;
    
    ptr_animal->makeSound();
    ptr_dog->makeSound();
    ptr_cat->makeSound();
    
    std::cout << "\n--- End of Tests ---" << std::endl;
    
    return 0;
}