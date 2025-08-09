/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:22:46 by odana             #+#    #+#             */
/*   Updated: 2025/08/08 15:21:38 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- Testing Constructors and Assignment Operators ---" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "--- Testing toInt() and toFloat() ---" << std::endl;
    std::cout << "a as int is " << a.toInt() << std::endl;
    std::cout << "b as int is " << b.toInt() << std::endl;
    std::cout << "c as int is " << c.toInt() << std::endl;
    std::cout << "d as int is " << d.toInt() << std::endl;
    std::cout << "a as float is " << a.toFloat() << std::endl;
    std::cout << "b as float is " << b.toFloat() << std::endl;
    std::cout << "c as float is " << c.toFloat() << std::endl;
    std::cout << "d as float is " << d.toFloat() << std::endl;

    std::cout << "\n--- Testing Comparison Operators ---" << std::endl;
    Fixed f1(5.5f);
    Fixed f2(5.5f);
    Fixed f3(6.0f);

    std::cout << "f1 is " << f1 << ", f2 is " << f2 << ", f3 is " << f3 << std::endl;
    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 >= f2: " << (f1 >= f2) << std::endl;
    std::cout << "f1 <= f2: " << (f1 <= f2) << std::endl;
    std::cout << "f1 != f2: " << (f1 != f2) << std::endl;
    std::cout << "f1 > f3: " << (f1 > f3) << std::endl;
    std::cout << "f1 < f3: " << (f1 < f3) << std::endl;

    std::cout << "\n--- Testing Arithmetic Operators ---" << std::endl;
    Fixed add = f1 + f3;
    Fixed sub = f3 - f1;
    Fixed mul = f1 * f3;
    Fixed div = f3 / f1;

    std::cout << "f1 + f3 = " << add << " (Expected: 11.5)" << std::endl;
    std::cout << "f3 - f1 = " << sub << " (Expected: 0.5)" << std::endl;
    std::cout << "f1 * f3 = " << mul << " (Expected: 33.0)" << std::endl;
    std::cout << "f3 / f1 = " << div << " (Expected: ~1.09)" << std::endl;

    std::cout << "\n--- Testing Increment/Decrement Operators ---" << std::endl;
    Fixed i(10.0f);
    std::cout << "Initial value of i: " << i << std::endl;
    std::cout << "Pre-increment ++i: " << ++i << std::endl;
    std::cout << "Value of i after pre-increment: " << i << std::endl;
    std::cout << "Post-increment i++: " << i++ << std::endl;
    std::cout << "Value of i after post-increment: " << i << std::endl;
    std::cout << "Pre-decrement --i: " << --i << std::endl;
    std::cout << "Value of i after pre-decrement: " << i << std::endl;
    std::cout << "Post-decrement i--: " << i-- << std::endl;
    std::cout << "Value of i after post-decrement: " << i << std::endl;

    std::cout << "\n--- Testing min() and max() Static Functions ---" << std::endl;
    Fixed m1(20.0f);
    Fixed m2(15.0f);
    const Fixed m3(25.0f);
    const Fixed m4(10.0f);

    std::cout << "m1 is " << m1 << ", m2 is " << m2 << std::endl;
    std::cout << "min(m1, m2): " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2): " << Fixed::max(m1, m2) << std::endl;
    std::cout << "min(m3, m4): " << Fixed::min(m3, m4) << std::endl;
    std::cout << "max(m3, m4): " << Fixed::max(m3, m4) << std::endl;
    
    return 0;
}