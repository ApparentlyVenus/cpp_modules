/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:22:26 by odana             #+#    #+#             */
/*   Updated: 2025/09/14 13:26:17 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <climits>
#include <sys/time.h>
#include <iomanip>
#include <stdexcept>

class PmergeMe
{
private:
    std::vector<int>    _inputNumbers;
    std::vector<int>    _sortedVector;
    std::deque<int>     _sortedDeque;
    double              _vectorTime;
    double              _dequeTime;
    int                 _vectorComparisons;
    int                 _dequeComparisons;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void    parseInput(int argc,  char **argv);
    void    sort();
    void    displayResults() const;

private:
    // Time Utils:
    double  getCurrentTime();

    // Parsing Utils:
    bool    isValidInteger(const std::string& arg);
    bool    containsDuplicates();

    // Sorting Utils:
    bool    compareVector(int a, int b);
    bool    compareDeque(int a, int b);
    int     binarySearchVector(const std::vector<int>& container, 
                int value, int left, int right);
    int     binarySearchDeque(const std::deque<int>& container, 
                int value, int left, int right);
    
    // Jacobsthal Utils:
    std::vector<int>    generateJacobsthalSequence(int maxSize);
    std::vector<int>    createInsertionOrder(const std::vector<int>& jacobsthal,
                            int pendSize, bool hasExtra);
    
    // Vector Sort:
    void    fordJohnsonVector(std::vector<int>& container);
    void    createPairsVector(const std::vector<int>& container,
                std::vector<int>& mainChain, std::vector<int>& pendChain,
                int& extra, bool& hasExtra);
    void    rotatePendVector(std::vector<int>& pendChain,
                const std::vector<int>& originalMain,
                const std::vector<int>& currentMain);
    void    insertPendVector(std::vector<int>& mainChain, 
                std::vector<int>& pendChain, int extra, bool hasExtra);

    // Deque Sort:
    void    fordJohnsonDeque(std::deque<int>& container);
    void    createPairsDeque(const std::deque<int>& container,
                std::deque<int>& mainChain, std::deque<int>& pendChain,
                int& extra, bool& hasExtra);
    void    rotatePendDeque(std::deque<int>& pendChain,
                const std::deque<int>& originalMain,
                const std::deque<int>& currentMain);
    void    insertPendDeque(std::deque<int>& mainChain, 
                std::deque<int>& pendChain);
        


};

#endif