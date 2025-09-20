/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/20 11:17:26 by odana            ###   ########.fr       */
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

void    PmergeMe::parseInput(int argc, char** argv)
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
}

void    PmergeMe::sort() 
{
    _sortedVector.assign(_inputNumbers.begin(), _inputNumbers.end());
    _sortedDeque.assign(_inputNumbers.begin(), _inputNumbers.end());
    
    _vectorComparisons = 0;
    _dequeComparisons = 0;
    
    double startTime = getCurrentTime();
    _sortedVector = sortVector(_sortedVector);
    double endTime = getCurrentTime();
    _vectorTime = endTime - startTime;
    
    startTime = getCurrentTime();
    _sortedDeque = sortDeque(_sortedDeque);
    endTime = getCurrentTime();
    _dequeTime = endTime - startTime;
}

bool    PmergeMe::isValidInteger(const std::string& arg)
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

double  PmergeMe::getCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void    PmergeMe::displayResults() const
{
    std::cout << "Before:";
    for (size_t i = 0; i < _inputNumbers.size(); i++) 
        std::cout << " " << _inputNumbers[i];
    std::cout << std::endl;
    
    std::cout << "After (vector):";
    for (size_t i = 0; i < _sortedVector.size(); i++) 
        std::cout << " " << _sortedVector[i];
    std::cout << std::endl;
    
    std::cout << "After (deque):";
    for (size_t i = 0; i < _sortedDeque.size(); i++) 
        std::cout << " " << _sortedDeque[i];
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _inputNumbers.size() 
              << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Number of comparisons for std::vector: " << _vectorComparisons << std::endl;
    std::cout << "Time to process a range of " << _inputNumbers.size() 
              << " elements with std::deque : " << _dequeTime << " us" << std::endl;
    std::cout << "Number of comparisons for std::deque: " << _dequeComparisons << std::endl;
}


std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t maxSize)
{
    std::vector<size_t> jacobsthal;
    if (maxSize == 0) 
        return jacobsthal;

    jacobsthal.push_back(0);
    if (maxSize == 1) 
        return jacobsthal;

    jacobsthal.push_back(1);
    while (jacobsthal.back() < maxSize) 
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<size_t> PmergeMe::createInsertionOrder(const std::vector<size_t>& jacobSequence, size_t pendSize)
{
    std::vector<size_t> insertionOrder;
    std::vector<bool> used(pendSize + 1, false);
    
    for (size_t i = 0; i < jacobSequence.size(); ++i) 
    {
        size_t x = jacobSequence[i];
        while (x > 1 && x <= pendSize) 
        {
            if (!used[x]) 
            {
                insertionOrder.push_back(x);
                used[x] = true;
            }
            x--;
        }
    }

    // Ensure all remaining indices from 2 to pendSize are included
    for (size_t x = 2; x <= pendSize; ++x) 
    {
        if (!used[x]) 
        {
            insertionOrder.push_back(x);
            used[x] = true;
        }
    }

    return insertionOrder;
}

bool    PmergeMe::compareVector(int a, int b) 
{
    _vectorComparisons++;
    return (a < b);
}

bool    PmergeMe::compareDeque(int a, int b) 
{
    _dequeComparisons++;
    return (a < b);
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& container, int value, size_t maxIndex) 
{
    if (container.empty()) 
        return 0;
    
    int low = 0;
    int high = static_cast<int>(maxIndex);
    if (high >= static_cast<int>(container.size())) 
        high = static_cast<int>(container.size()) - 1;
    
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        
        if (compareVector(container[mid], value))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (static_cast<size_t>(low));
}

std::vector<int> PmergeMe::sortVector(std::vector<int>& data)
{
    // Handle base cases
    if (data.empty()) 
        return (std::vector<int>());
    if (data.size() == 1) 
        return (data);
    
    if (data.size() == 2) 
    {
        std::vector<int> result = data;
        if (compareVector(result[1], result[0])) 
            std::swap(result[0], result[1]);
        return (result);
    }
    
    bool isOdd = (data.size() % 2 == 1);
    std::vector<int> main, pend;
    
    // Create pairs
    for (size_t i = 0; i < data.size() - (isOdd ? 1 : 0); i += 2) 
    {
        if (compareVector(data[i+1], data[i])) 
        {
            main.push_back(data[i]);
            pend.push_back(data[i + 1]);
        } 
        else 
        {
            pend.push_back(data[i]);
            main.push_back(data[i + 1]);
        }
    }
    
    // Add odd element
    if (isOdd) 
        pend.push_back(data.back());
    
    // Recursively sort main elements
    std::vector<int> newMain = sortVector(main);
    std::vector<int> newPend;
    
    // rotate pend vector
    for (size_t i = 0; i < newMain.size(); ++i) 
    {
        for (size_t j = 0; j < main.size(); ++j) 
        {
            if (main[j] == newMain[i]) 
            {
                newPend.push_back(pend[j]);
                break;
            }
        }
    }
    
    // Add odd element
    if (isOdd) 
        newPend.push_back(pend.back());
    
    // Insert pending elements into the main chain
    insertPendVector(newMain, newPend);
    
    return (newMain);
}

void PmergeMe::insertPendVector(std::vector<int>& mainChain, const std::vector<int>& pendChain)
{
    if (pendChain.empty()) 
        return;

    // Generate the Jacobsthal sequence and calculate the insertion order
    std::vector<size_t> jacobSequence = generateJacobsthalSequence(pendChain.size());
    std::vector<size_t> insertionOrder = createInsertionOrder(jacobSequence, pendChain.size());

    size_t searchLimit = 3;
    mainChain.insert(mainChain.begin(), pendChain[0]);

    for (size_t i = 0; i < insertionOrder.size(); ++i) 
    {
        if (i > 0 && insertionOrder[i] > insertionOrder[i - 1]) 
        {
            if (searchLimit <= mainChain.size() / 2) 
                searchLimit = 2 * searchLimit + 1;
            else 
                searchLimit = mainChain.size();
        }

        if (insertionOrder[i] <= pendChain.size() && insertionOrder[i] != 1) 
        {
            size_t pendIndex = insertionOrder[i] - 1;
            int valueToInsert = pendChain[pendIndex];

            size_t maxSearchIndex = std::min(searchLimit - 1, mainChain.size());
            size_t insertPosition = binarySearchVector(mainChain, valueToInsert, maxSearchIndex);

            mainChain.insert(mainChain.begin() + insertPosition, valueToInsert);
        }
    }
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& container, int value, size_t maxIndex) 
{
    if (container.empty()) 
        return (0);
    
    int low = 0;
    int high = static_cast<int>(maxIndex);
    if (high >= static_cast<int>(container.size())) 
        high = static_cast<int>(container.size()) - 1;
    
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        
        if (compareDeque(container[mid], value))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (static_cast<size_t>(low));
}

std::deque<int> PmergeMe::sortDeque(std::deque<int>& data)
{
    // Handle base cases
    if (data.empty()) 
        return (std::deque<int>());
    if (data.size() == 1) 
        return (data);
    
    if (data.size() == 2) 
    {
        std::deque<int> result = data;
        if (compareDeque(result[1], result[0])) 
            std::swap(result[0], result[1]);
        return (result);
    }
    
    bool isOdd = (data.size() % 2 == 1);
    std::deque<int> main, pend;
    
    // Create pairs
    for (size_t i = 0; i < data.size() - (isOdd ? 1 : 0); i += 2) 
    {
        if (compareDeque(data[i+1], data[i])) 
        {
            main.push_back(data[i]);
            pend.push_back(data[i + 1]);
        } 
        else 
        {
            pend.push_back(data[i]);
            main.push_back(data[i + 1]);
        }
    }
    
    // Add odd element
    if (isOdd) 
        pend.push_back(data.back());
    
    // Recursively sort main elements
    std::deque<int> newMain = sortDeque(main);
    std::deque<int> newPend;
    
    // rotate pend deque
    for (size_t i = 0; i < newMain.size(); ++i) 
    {
        for (size_t j = 0; j < main.size(); ++j) 
        {
            if (main[j] == newMain[i]) 
            {
                newPend.push_back(pend[j]);
                break;
            }
        }
    }
    
    // Add odd element
    if (isOdd) 
        newPend.push_back(pend.back());
    
    // Insert pending elements into the main chain
    insertPendDeque(newMain, newPend);
    
    return (newMain);
}

void PmergeMe::insertPendDeque(std::deque<int>& mainChain, const std::deque<int>& pendChain)
{
    if (pendChain.empty()) 
        return;

    // Generate the Jacobsthal sequence and calculate the insertion order
    std::vector<size_t> jacobSequence = generateJacobsthalSequence(pendChain.size());
    std::vector<size_t> insertionOrder = createInsertionOrder(jacobSequence, pendChain.size());

    size_t searchLimit = 3;
    mainChain.insert(mainChain.begin(), pendChain[0]);

    for (size_t i = 0; i < insertionOrder.size(); ++i) 
    {
        if (i > 0 && insertionOrder[i] > insertionOrder[i - 1]) 
        {
            if (searchLimit <= mainChain.size() / 2) 
                searchLimit = 2 * searchLimit + 1;
            else 
                searchLimit = mainChain.size();
        }

        if (insertionOrder[i] <= pendChain.size() && insertionOrder[i] != 1) 
        {
            size_t pendIndex = insertionOrder[i] - 1;
            int valueToInsert = pendChain[pendIndex];

            size_t maxSearchIndex = std::min(searchLimit - 1, mainChain.size());
            size_t insertPosition = binarySearchDeque(mainChain, valueToInsert, maxSearchIndex);

            mainChain.insert(mainChain.begin() + insertPosition, valueToInsert);
        }
    }
}