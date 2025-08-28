/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:40:37 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:07:59 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

void    Span::addNumber(int num)
{
    if (_data.size() + 1 > _maxSize)
        throw std::runtime_error("Adding num would exceed maximum size");
    _data.push_back(num);
}

unsigned int    Span::shortestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements for span calculation");
    std::vector<int> sortedData = _data;
    std::sort(sortedData.begin(), sortedData.end());
    
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedData.size(); i++)
    {
        unsigned int span = sortedData[i] - sortedData[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return (minSpan);
}

unsigned int    Span::longestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements for span calculation");
    std::vector<int>::iterator min = std::min_element(_data.begin(), _data.end());
    std::vector<int>::iterator max = std::max_element(_data.begin(), _data.end());

    return (*max - *min);
}