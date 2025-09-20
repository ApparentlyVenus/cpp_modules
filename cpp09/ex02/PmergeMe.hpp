/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/20 10:55:38 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <sys/time.h>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _inputNumbers;
    std::vector<int> _sortedVector;
    std::deque<int> _sortedDeque;
    double _vectorTime;
    double _dequeTime;
    size_t _vectorComparisons;
    size_t _dequeComparisons;

    // Helper functions
    bool isValidInteger(const std::string& arg);
    double getCurrentTime();
    
    // Jacobsthal sequence generation
    std::vector<size_t> generateJacobsthalSequence(size_t maxSize);
    std::vector<size_t> createInsertionOrder(const std::vector<size_t>& jacobSequence, size_t pendSize);
    
    // Comparison functions
    bool compareVector(int a, int b);
    bool compareDeque(int a, int b);
    
    // Binary search functions
    size_t binarySearchVector(const std::vector<int>& container, int value, size_t maxIndex);
    
    // Main Ford-Johnson algorithm functions
    std::vector<int> sortVector(std::vector<int>& data);
    void insertPendVector(std::vector<int>& mainChain, const std::vector<int>& pendChain);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void sort();
    void displayResults() const;
};

#endif