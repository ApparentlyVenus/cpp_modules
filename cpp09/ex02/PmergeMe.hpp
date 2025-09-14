/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:22:26 by odana             #+#    #+#             */
/*   Updated: 2025/09/14 10:57:29 by odana            ###   ########.fr       */
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
    double  getCurrentTime() 

    // Parsing Utils:
    bool    isValidInteger(const std::string& arg);
    bool    containsDuplicates() 

};

#endif