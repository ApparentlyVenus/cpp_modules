/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:18:15 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:35:01 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <iterator>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::it it = mstack.begin();
    MutantStack<int>::it ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    MutantStack<int> mstack2;
    mstack2.push(10);
    mstack2.push(20);
    mstack2.push(30);
    
    for (MutantStack<int>::it iter = mstack2.begin(); iter != mstack2.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    for (MutantStack<int>::it iter = mstack2.begin(); iter != mstack2.end(); ++iter) {
        *iter += 5;
    }
    
    for (MutantStack<int>::it iter = mstack2.begin(); iter != mstack2.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    MutantStack<int> empty_stack;
    int count = 0;
    for (MutantStack<int>::it iter = empty_stack.begin(); iter != empty_stack.end(); ++iter) {
        count++;
    }
    std::cout << count << std::endl;

    const MutantStack<int> const_stack = mstack2;
    for (MutantStack<int>::const_it citer = const_stack.begin(); citer != const_stack.end(); ++citer) {
        std::cout << *citer << " ";
    }
    std::cout << std::endl;

    MutantStack<int> ops_stack;
    ops_stack.push(1);
    ops_stack.push(2);
    ops_stack.push(3);
    
    std::cout << ops_stack.size() << std::endl;
    std::cout << ops_stack.top() << std::endl;
    ops_stack.pop();
    std::cout << ops_stack.top() << std::endl;
    std::cout << (ops_stack.empty() ? "Yes" : "No") << std::endl;

    MutantStack<int> original;
    original.push(100);
    original.push(200);
    
    std::stack<int> regular_stack(original);
    std::cout << regular_stack.size() << std::endl;
    std::cout << regular_stack.top() << std::endl;

    return 0;
}