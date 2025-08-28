/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:15:07 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 14:21:52 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template<typename T>
class Array
{
    private:
        T*          _array;
        size_t      _size;
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
    
        size_t size() const;
    
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
    
        class OutOfBoundsException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return "Array index out of bounds";
            }
        };
};


template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
    if (n > 0)
    {
        _array = new T[n]();
    }
}

template<typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(other._size)
{
    if (_size > 0)
    {
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        
        _size = other._size;
        if (_size > 0)
        {
            _array = new T[_size];
            for (size_t i = 0; i < _size; i++)
            {
                _array[i] = other._array[i];
            }
        }
        else
        {
            _array = NULL;
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template<typename T>
size_t Array<T>::size() const
{
    return _size;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
    {
        throw OutOfBoundsException();
    }
    return _array[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
    {
        throw OutOfBoundsException();
    }
    return _array[index];
}

#endif
