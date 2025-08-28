/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:59:47 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:39:54 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(42);
    vec.push_back(100);
    vec.push_back(42);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found 42 at position: " << (it - vec.begin()) << std::endl;
        std::cout << "Value: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 999);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Correctly caught: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(-5);
    lst.push_back(0);
    lst.push_back(15);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 0);
        std::cout << "Found 0 in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_front(5);
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << "Found 5 in deque: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::vector<int> empty_vec;
    try {
        easyfind(empty_vec, 1);
        std::cout << "ERROR: Should have thrown!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Empty container handled: " << e.what() << std::endl;
    }

    std::vector<int> single_vec;
    single_vec.push_back(42);
    try {
        std::vector<int>::iterator it = easyfind(single_vec, 42);
        std::cout << "Found single element: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(single_vec, 99);
        std::cout << "ERROR: Should have thrown!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Single element not found: " << e.what() << std::endl;
    }

    std::vector<int> neg_vec;
    neg_vec.push_back(-10);
    neg_vec.push_back(-1);
    neg_vec.push_back(0);
    neg_vec.push_back(1);
    
    try {
        std::vector<int>::iterator it = easyfind(neg_vec, -1);
        std::cout << "Found -1: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::vector<int> dup_vec;
    dup_vec.push_back(1);
    dup_vec.push_back(2);
    dup_vec.push_back(3);
    dup_vec.push_back(2);
    dup_vec.push_back(4);
    
    try {
        std::vector<int>::iterator it = easyfind(dup_vec, 2);
        std::cout << "First occurrence of 2 at position: " << (it - dup_vec.begin()) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}