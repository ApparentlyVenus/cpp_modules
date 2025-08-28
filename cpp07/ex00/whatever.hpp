/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:58:46 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 14:02:30 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template<typename T>
void    swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T&    min(const T& a, const T& b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
const T&    max(const T& a, const T& b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif