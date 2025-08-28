/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:18:15 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 14:19:16 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
    Array<int> empty;
    Array<int> numbers(3);
    
    std::cout << "Empty size: " << empty.size() << std::endl;
    std::cout << "Numbers size: " << numbers.size() << std::endl;
    
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    std::cout << "Values: " << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;
    
    Array<int> copy(numbers);
    numbers[0] = 999;
    std::cout << "Original[0]: " << numbers[0] << ", Copy[0]: " << copy[0] << std::endl;
    
    Array<int> assigned(1);
    assigned = copy;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    
    try {
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    Array<std::string> strings(2);
    strings[0] = "Saba7o";
    strings[1] = "Kifak";
    std::cout << "Strings: " << strings[0] << " " << strings[1] << std::endl;
    
    return 0;
}