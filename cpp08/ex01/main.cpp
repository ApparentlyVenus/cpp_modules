/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:59:47 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:08:48 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try 
    {
        const unsigned int big_size = 15000;
        Span bigSpan(big_size);
        
        srand(time(0));
        
        std::cout << "Adding " << big_size << " random numbers..." << std::endl;
        for (unsigned int i = 0; i < big_size; i++)
            bigSpan.addNumber(rand() % 1000000);
        
        std::cout << "Calculating spans..." << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        Span emptySpan(5);
        emptySpan.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Empty span error: " << e.what() << std::endl;
    }

    try
    {
        Span fullSpan(2);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        fullSpan.addNumber(3);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Overflow error: " << e.what() << std::endl;
    }

    return 0;
}