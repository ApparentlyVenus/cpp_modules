/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:03:34 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 14:07:51 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T, typename F>
void    iter(T* arr, size_t n, F f)
{
    for (size_t i = 0; i < n; i++)
        f(array[i]);
}

template<typename T, typename F>
void    iter(const T* arr, size_t n, F f)
{
    for (size_t i = 0; i < n; i++)
        f(array[i]);
}

#endif