/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:22:26 by odana             #+#    #+#             */
/*   Updated: 2025/09/02 19:29:51 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iomanip>
# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <exception>
# include <ctime>
# include <sys/time.h>
# include <climits>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void processArguments(int argc, char** argv);
    void displayResults();
    void sortWithDeque();
    void sortWithVector();

private:
    std::vector<int>    _inputNumbers;
    std::vector<int>    _sortedVector;
    std::deque<int>     _sortedDeque;
    
    double _vectorTime;
    double _dequeTime;

    int _vectorComparisons;
    int _dequeComparisons;
    
    // Input Processing 
    void parseInput(int argc, char** argv);
    bool isValidInteger(const std::string& str);
    bool containsDuplicates();
    
    // Jacobsthal & Helper Functions
    std::vector<int> generateJacobsthalSequence(int maxSize);
    std::vector<int> createInsertionOrder(int pendSize);
    double getCurrentTime();
    
    // Display 
    void printSequence(const std::vector<int>& sequence, const std::string& label);
    void printTimingResults();
    
    // FORD-JOHNSON ALGORITHM - VECTOR IMPLEMENTATION
    std::vector<int> fordJohnsonVector(std::vector<int>& data);
    
    void createPairsVector(const std::vector<int>& data, 
                          std::vector<int>& mainChain, 
                          std::vector<int>& pendChain, 
                          int& extraElement, 
                          bool& hasExtra);
    
    std::vector<int> recursiveSortVector(std::vector<int>& mainChain);
    
    void insertPendElementsVector(std::vector<int>& mainChain, 
                                 const std::vector<int>& pendChain, 
                                 int extraElement, 
                                 bool hasExtra);
    
    int binarySearchVector(const std::vector<int>& container, 
                          int value, 
                          int left, 
                          int right);
    
    void insertAtPositionVector(std::vector<int>& container, 
                               int value, 
                               int position);
    
    // FORD-JOHNSON ALGORITHM - DEQUE IMPLEMENTATION
    std::deque<int> fordJohnsonDeque(std::deque<int>& data);
    
    void createPairsDeque(const std::deque<int>& data, 
                         std::deque<int>& mainChain, 
                         std::deque<int>& pendChain, 
                         int& extraElement, 
                         bool& hasExtra);
    
    std::deque<int> recursiveSortDeque(std::deque<int>& mainChain);
    
    void insertPendElementsDeque(std::deque<int>& mainChain, 
                                const std::deque<int>& pendChain, 
                                int extraElement, 
                                bool hasExtra);

    int binarySearchDeque(const std::deque<int>& container, 
                         int value, 
                         int left, 
                         int right);
    
    void insertAtPositionDeque(std::deque<int>& container, 
                              int value, 
                              int position);
    
};

#endif