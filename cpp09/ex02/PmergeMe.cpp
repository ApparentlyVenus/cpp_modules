/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/02 17:37:42 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    :   _inputNumbers(other._inputNumbers),
        _sortedVector(other._sortedVector),
        _sortedDeque(other._sortedDeque),
        _vectorTime(other._vectorTime),
        _dequeTime(other._dequeTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _inputNumbers = other._inputNumbers;
        _sortedVector = other._sortedVector;
        _sortedDeque = other._sortedDeque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return (*this);
}

PmergeMe::PmergeMe() {}

void    PmergeMe::processArguments(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    parseInput(argc, argv);
    if (containsDuplicates())
        throw std::runtime_error("Error");
}

void    PmergeMe::parseInput(int argc, char** argv)
{
    _inputNumbers.clear();
    for (size_t i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        if (!isValidInteger(arg))
            throw std::runtime_error("Error");
        std::istringstream iss(arg);
        int num;
        iss >> num;
        _inputNumbers.push_back(num);
    }
    if (_inputNumbers.empty())
        throw std::runtime_error("Error");
}
        
bool    PmergeMe::isValidInteger(const std::string& arg)
{
    if (arg.empty())
        return (false);
    if (arg.length() > 1 && arg[0] == '0')
        return (false);
    for (size_t i = 0; i < arg.length(); i++)
    {
        if (!std::isdigit(arg[i]))
            return (false);
    }
    std::istringstream iss(arg);
    long long num;
    if ((!iss >> num) || !iss.eof())
        return (false);
    if (num <= 0 || num > INT_MAX)
        return (false);
    return (true);
}

bool    PmergeMe::containsDuplicates() 
{
    for (size_t i = 0; i < _inputNumbers.size(); i++) 
    {
        for (size_t j = i + 1; j < _inputNumbers.size(); j++) 
        {
            if (_inputNumbers[i] == _inputNumbers[j])
                return (true);
        }
    }
    return (false);
}

void    PmergeMe::createPairsVector(const std::vector<int>& data,
            std::vector<int>& mainChain, std::vector<int>& pendChain,
                int& extraElement, bool& hasExtra)
{
    mainChain.clear();
    pendChain.clear();
    hasExtra = false;
    size_t  pairCount = data.size() / 2;
    if (data.size() % 2 == 1)
    {
        hasExtra = true;
        extraElement = data[data.size() - 1];
    }
    for (size_t i = 0; i < pairCount; i++)
    {
        int first = data[i * 2];
        int second = data[i * 2 + 1];
        if (first > second)
        {
            mainChain.push_back(first);
            pendChain.push_back(second);
        }
        else
        {
            mainChain.push_back(second);
            pendChain.push_back(first);
        }
    }
    
}

std::vector<int>    PmergeMe::recursiveSortVector(std::vector<int>& mainChain)
{
    if (mainChain.size() <= 1)
        return (mainChain);

    std::vector<int> newMainChain;
    std::vector<int> newPendChain;
    int newExtraElement;
    bool newHasExtra;

    createPairsVector(mainChain, newMainChain, newPendChain, newExtraElement, newHasExtra);
    std::vector<int> sortedMain = recursiveSortVector(newMainChain);

    // insert pend elements using jackobsthl (steps VI-IX)
    // for now im just returning sorted main chain

    return (sortedMain);
}

std::vector<int>    PmergeMe::generateJacobsthalSequence(int maxSize)
{
    std::vector<int>    jacobsthal;
    
    if (maxSize <= 0)
        return (jacobsthal);

    jacobsthal.push_back(1);
    if (maxSize == 1)
        return (jacobsthal);
        
    // Sequence starts with 0, 1, 1.. we have to skip the first 0 and 1
    // Treat it as if we are starting with J(3)
    int prev2 = 1;
    int prev1 = 1;
    
    while (true)
    {
        // Formula: J(n) = J(n -1) + 2 * J(n - 2)
        int next = prev1 + 2 * prev2;
        if (next > maxSize)
            break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }
    return (jacobsthal);
}

std::vector<int> PmergeMe::createInsertionOrder(int pendSize)
{
    if (pendSize <= 1)
    {
        std::vector<int> order;
        if (pendSize == 1)
            order.push_back(1);
        return (order);
    }
    
    std::vector<int>    jacobsthal = generateJacobsthalSequence(pendSize);
    std::vector<int>    insertionOrder;

    // rule: insert first element 
    insertionOrder.push_back(1);
    
    size_t  jacobIndex = 1;
    int     previousJacob = 1;
    
    while (jacobIndex < jacobsthal.size())
    {
        int currentJacob = jacobsthal[jacobIndex];
        for (int j = currentJacob; j > previousJacob; j--)
            insertionOrder.push_back(j);
        previousJacob = currentJacob;
        jacobIndex++;
        if (currentJacob >= pendSize)
            break;
    }
    for (int i = previousJacob + 1; i <= pendSize; i++)
        insertionOrder.push_back(1);
    return (insertionOrder);
}