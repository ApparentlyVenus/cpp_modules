/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/14 10:57:35 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0), _vectorComparisons(0), _dequeComparisons(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    :   _inputNumbers(other._inputNumbers),
        _sortedVector(other._sortedVector),
        _sortedDeque(other._sortedDeque),
        _vectorTime(other._vectorTime),
        _dequeTime(other._dequeTime),
        _vectorComparisons(other._vectorComparisons),
        _dequeComparisons(other._dequeComparisons) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _inputNumbers = other._inputNumbers;
        _sortedVector = other._sortedVector;
        _sortedDeque = other._sortedDeque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
        _vectorComparisons = other._vectorComparisons;
        _dequeComparisons = other._dequeComparisons;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    _inputNumbers.clear();
    for (int i = 1; i < argc; i++)
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
    if (containsDuplicates())
        throw std::runtime_error("Error");
}
        
bool PmergeMe::isValidInteger(const std::string& arg)
{
    if (arg.empty())
        return (false);
        
    if (arg.length() > 1 && arg[0] == '0')
        return (false);
    
    std::istringstream iss(arg);
    long long num;
    if (!(iss >> num) || !iss.eof())
        return (false);
    if (num <= 0 || num > INT_MAX)
        return (false);
    return (true);
}

bool PmergeMe::containsDuplicates() 
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

double PmergeMe::getCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void PmergeMe::displayResults() 
{
    std::cout << "Before:";
    for (size_t i = 0; i < _inputNumbers.size(); i++) 
        std::cout << " " << _inputNumbers[i];
    std::cout << std::endl;
    
    std::cout << "After:";
    for (size_t i = 0; i < _sortedVector.size(); i++) 
        std::cout << " " << _sortedVector[i];
    std::cout << std::endl;
    
    std::cout << std::fixed << std::setprecision(7) << "Time to process a range of " << _inputNumbers.size() 
              << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Number of comparisons for std::vector: " << _vectorComparisons << std::endl;
}

