/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:57:44 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:07:08 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <stdexcept>
# include <iterator>
# include <climits>

class Span
{
    private:
        std::vector<int>    _data;
        unsigned int        _maxSize;
        
    public:
        Span(unsigned int n);
        
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        
        void    addNumber(int num);
        template<typename T>
        void    addRange(T first, T last)
        {
            size_t  distance = std::distance(first, last);
            if (_data.size() + distance > _maxSize)
                throw std::runtime_error("Adding range would exceed maximum size");
            _data.insert(_data.end(), first, last);
        }
};

#endif