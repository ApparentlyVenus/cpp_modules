/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:49:54 by odana             #+#    #+#             */
/*   Updated: 2025/09/14 11:49:58 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try {
        PmergeMe sorter;
        
        // Parse input from command line
        sorter.parseInput(argc, argv);
        
        // Sort using both containers and time them
        sorter.sort();
        
        // Display results
        sorter.displayResults();
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}