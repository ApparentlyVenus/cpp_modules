/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/17 14:07:14 by odana            ###   ########.fr       */
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
    fordJohnsonVector(_sortedVector);
    double endTime = getCurrentTime();
    _vectorTime = endTime - startTime;
    
    // startTime = getCurrentTime();
    // fordJohnsonDeque(_sortedDeque);
    // endTime = getCurrentTime();
    // _dequeTime = endTime - startTime;
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
    
    std::cout << "After:";
    for (size_t i = 0; i < _sortedVector.size(); i++) 
        std::cout << " " << _sortedVector[i];
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _inputNumbers.size() 
              << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Number of comparisons for std::vector: " << _vectorComparisons << std::endl;
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

std::vector<int> PmergeMe::createInsertionOrder(const std::vector<int>& jacob, int pendSize, bool hasExtra)
{
    std::vector<int> insertionOrder;
    std::vector<bool> used(pendSize + 2, false); // +2 to handle extra element
    
    int prevJacob = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        int currentJacob = jacob[i];
        // Insert from currentJacob down to prevJacob+1 in descending order
        for (int j = currentJacob; j > prevJacob; --j)
        {
            if (j <= pendSize && !used[j]) {
                insertionOrder.push_back(j);
                used[j] = true;
            }
        }
        prevJacob = currentJacob;
    }
    
    // Add any remaining elements from 2 to pendSize that haven't been used
    for (int j = 2; j <= pendSize; ++j) {
        if (!used[j]) {
            insertionOrder.push_back(j);
            used[j] = true;
        }
    }
    
    // Add extra element position if needed
    if (hasExtra) {
        insertionOrder.push_back(pendSize + 1);
    }
    
    // Debug statement to print the complete insertion order
    std::cout << "Final insertion order: ";
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        std::cout << insertionOrder[i];
        if (i < insertionOrder.size() - 1) std::cout << " ";
    }
    std::cout << " (pendSize=" << pendSize << ", hasExtra=" << hasExtra << ")" << std::endl;
    
    return insertionOrder;
}
                    

bool    PmergeMe::compareVector(int a, int b) 
{
    _vectorComparisons++;
    std::cout << "Comparison #" << _vectorComparisons << ": " << a << " < " << b << " = " << (a < b) << std::endl;
    return (a < b);
}

bool    PmergeMe::compareDeque(int a, int b) 
{
    _dequeComparisons++;
    return (a < b);
}

int PmergeMe::binarySearchVector(const std::vector<int>& container, int value, int left, int right) 
{
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (compareVector(container[mid], value))
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

int PmergeMe::binarySearchDeque(const std::deque<int>& container, int value, int left, int right) 
{
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (compareDeque(container[mid], value))
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}



void    PmergeMe::fordJohnsonVector(std::vector<int>& container)
{
    if (container.size() <= 1)
        return ;
    
    std::vector<int> mainChain, pendChain;
    int extra = -1;
    bool hasExtra = false;
    createPairsVector(container, mainChain, pendChain, extra, hasExtra);
    
    std::vector<int> originalMainOrder = mainChain;
    
    fordJohnsonVector(mainChain);
    rotatePendVector(pendChain, originalMainOrder, mainChain);
    insertPendVector(mainChain, pendChain, extra, hasExtra);

    container = mainChain;
}

void    PmergeMe::createPairsVector(const std::vector<int>& container,
                                    std::vector<int>& mainChain,
                                    std::vector<int>& pendChain,
                                    int& extra, bool& hasExtra)
{
    mainChain.clear();
    pendChain.clear();

    hasExtra = (container.size() % 2 == 1);
    size_t size = container.size();
    if (hasExtra)
    {
        extra = container.back();
        size--;
    }
    for (size_t i = 0; i < size; i += 2)
    {
        int first = container[i];
        int second = container[i + 1];
        
        if (compareVector(first, second))
        {
            mainChain.push_back(second);
            pendChain.push_back(first);
        }
        else 
        {
            mainChain.push_back(first);
            pendChain.push_back(second);
        }
    }
}

void PmergeMe::rotatePendVector(std::vector<int>& pendChain,
                               const std::vector<int>& originalMain,
                               const std::vector<int>& currentMain)
{
    if (pendChain.empty())
        return;

    std::vector<int> newPendChain(pendChain.size());
    for (size_t currentPos = 0; currentPos < currentMain.size(); ++currentPos)
    {
        int currentElement = currentMain[currentPos];

        size_t originalPos = 0;
        for (size_t j = 0; j < originalMain.size(); j++)
        {
            if (originalMain[j] == currentElement)
            {
                originalPos = j;
                break;
            }
        }
        newPendChain[currentPos] = pendChain[originalPos];
    }
    pendChain = newPendChain;
}


int findCurrentPosition(const std::vector<int>& mainChain, int value)
{
    for (size_t i = 0; i < mainChain.size(); ++i) {
        if (mainChain[i] == value)
            return i;
    }
    return mainChain.size() - 1; // Fallback
}

void PmergeMe::insertPendVector(std::vector<int>& mainChain, std::vector<int>& pendChain,
                               int extra, bool hasExtra)
{
    if (pendChain.empty()) {
        if (hasExtra)
            mainChain.insert(mainChain.begin(), extra);
        return;
    }

    // Insert first element (b1 always goes first)
    int insertPos = 0;
    mainChain.insert(mainChain.begin(), pendChain[0]);
    
// if (pendChain.size() == 1) {
//     if (hasExtra) {
//         if (compareVector(extra, mainChain[0])) {
//             mainChain.insert(mainChain.begin(), extra);
//         } else if (compareVector(extra, mainChain[1])) {
//             mainChain.insert(mainChain.begin() + 1, extra);
//         } else {
//             mainChain.insert(mainChain.begin() + 2, extra);
//         }
//     }
//     return;
// }

    std::vector<int> jacob = generateJacobsthalSequence(pendChain.size() + (hasExtra ? 1 : 0));
    std::vector<int> insertionOrder = createInsertionOrder(jacob, pendChain.size(), hasExtra);

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int insertionIndex = insertionOrder[i];
        // Handle extra element
    if (insertionIndex > (int)pendChain.size()) {
        if (hasExtra) {
            // Use bounded search for extra element - it has no pair, but limit search space
            std::cout << "Extra element search: mainChain.size()=" << mainChain.size() << std::endl;
            insertPos = binarySearchVector(mainChain, extra, 0, mainChain.size());

            mainChain.insert(mainChain.begin() + insertPos, extra);
            hasExtra = false;
        }
        continue;
    }
        
        int pendIndex = insertionIndex - 1;
        if (pendIndex >= (int)pendChain.size() || pendIndex <= 0)
            continue;
        
        int elementToInsert = pendChain[pendIndex];
        
        int upperBound = pendIndex + i + 1;
        if (upperBound > (int)mainChain.size())
            upperBound = mainChain.size();
            
        insertPos = binarySearchVector(mainChain, elementToInsert, 0, upperBound);
        mainChain.insert(mainChain.begin() + insertPos, elementToInsert);
    }
}