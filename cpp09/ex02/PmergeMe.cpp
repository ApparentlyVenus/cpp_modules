/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:16:04 by odana             #+#    #+#             */
/*   Updated: 2025/09/04 17:06:32 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0), _vectorComparisons(0), _dequeComparisons(0) {}

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

PmergeMe::~PmergeMe() {}

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

        _vectorComparisons++;
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

void PmergeMe::insertPendElementsVector(std::vector<int>& mainChain,
                                        const std::vector<int>& pendChain,
                                        int extraElement, bool hasExtra)
{
    if (pendChain.empty()) {
        if (hasExtra) {
            int pos = binarySearchVector(mainChain, extraElement, 0, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, extraElement);
        }
        return;
    }

    mainChain.insert(mainChain.begin(), pendChain[0]);

    std::vector<int> insertionOrder = createInsertionOrder(pendChain.size());
    std::vector<int> jacob = generateJacobsthalSequence(pendChain.size());
    
    std::vector<int> searchLimits;
    searchLimits.push_back(0);
    searchLimits.push_back(1);
    int last_limit = 1;
    while (searchLimits.size() < jacob.size() + 2) {
        last_limit = (last_limit + 1) * 2 - 1;
        searchLimits.push_back(last_limit);
    }

    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        int pendIndex = insertionOrder[i] - 1;
        int value = pendChain[pendIndex];
        
        int groupIndex = 0;
        bool group_found = false;
        for (size_t j = 0; j < jacob.size(); ++j) {
            if (insertionOrder[i] <= jacob[j]) {
                groupIndex = j + 1;
                group_found = true;
                break;
            }
        }
        
        int searchRight;
        if (group_found) {
            searchRight = searchLimits[groupIndex];
        } else {
            // THIS WAS THE BUG. Elements larger than the last Jacobsthal number
            // were getting a search range of 0. Now they search the full chain.
            searchRight = mainChain.size();
        }

        int pos = binarySearchVector(mainChain, value, 0, std::min((int)mainChain.size(), searchRight));
        mainChain.insert(mainChain.begin() + pos, value);
    }

    if (hasExtra) {
        int pos = binarySearchVector(mainChain, extraElement, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, extraElement);
    }
}


std::vector<int> PmergeMe::recursiveSortVector(std::vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> largerElements;
    int extraElement = -1;
    bool hasExtra = data.size() % 2 != 0;
    if (hasExtra) {
        extraElement = data.back();
    }

    for (size_t i = 0; i < data.size() / 2; ++i) {
        int first = data[i * 2];
        int second = data[i * 2 + 1];
        _vectorComparisons++;
        if (first > second) {
            pairs.push_back(std::make_pair(first, second));
            largerElements.push_back(first);
        } else {
            pairs.push_back(std::make_pair(second, first));
            largerElements.push_back(second);
        }
    }

    std::vector<int> sortedLargerElements = recursiveSortVector(largerElements);

    std::vector<int> sortedMain;
    std::vector<int> sortedPend;
    
    for (size_t i = 0; i < sortedLargerElements.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (sortedLargerElements[i] == pairs[j].first) {
                sortedMain.push_back(pairs[j].first);
                sortedPend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    insertPendElementsVector(sortedMain, sortedPend, extraElement, hasExtra);
    return sortedMain;
}


std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }
    _vectorComparisons = 0; // Reset comparisons at the start
    return recursiveSortVector(data);
}

int PmergeMe::binarySearchVector(const std::vector<int>& container, int value, int left, int right) 
{
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        _vectorComparisons++;
        if (container[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

void PmergeMe::sortWithVector() 
{
    if (_inputNumbers.empty()) return;
    
    double startTime = getCurrentTime();
    
    std::vector<int> dataCopy = _inputNumbers;
    _sortedVector = fordJohnsonVector(dataCopy);
    
    double endTime = getCurrentTime();
    _vectorTime = endTime - startTime;
}

double PmergeMe::getCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void PmergeMe::displayResults() 
{
    printSequence(_inputNumbers, "Before:");
    printSequence(_sortedVector, "After:");
    printTimingResults();
}

void PmergeMe::printSequence(const std::vector<int>& sequence, const std::string& label) 
{
    std::cout << label;
    for (size_t i = 0; i < sequence.size(); i++) 
        std::cout << " " << sequence[i];
    std::cout << std::endl;
}

void PmergeMe::printTimingResults()
{
    std::cout << std::fixed << std::setprecision(7) << "Time to process a range of " << _inputNumbers.size() 
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
        insertionOrder.push_back(i);
    return (insertionOrder);
}