/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:03:37 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 14:14:19 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void print(const T& x)
{
    std::cout << x << " ";
}

template<typename T>
void increment(T& x)
{
    x++;
}

void printInt(const int& x)
{
    std::cout << "[" << x << "] ";
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Before: ";
    ::iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    ::iter(numbers, 5, increment<int>);
    std::cout << "After increment: ";
    ::iter(numbers, 5, print<int>);
    std::cout << std::endl;

    const int constNumbers[] = {10, 20, 30};
    std::cout << "Const array: ";
    ::iter(constNumbers, 3, printInt);
    std::cout << std::endl;

    std::string words[] = {"Hello", "World"};
    std::cout << "Strings: ";
    ::iter(words, 2, print<std::string>);
    std::cout << std::endl;

    return 0;
}