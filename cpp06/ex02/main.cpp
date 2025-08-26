/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:42:30 by odana             #+#    #+#             */
/*   Updated: 2025/08/26 16:00:22 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base*   generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            std::cout << "Generated A" << std::endl;
            return (new A());
        case 1:
            std::cout << "Generated B" << std::endl;
            return (new B());
        case 2:
            std::cout << "Generated C" << std::endl;
            return (new C());
    }
}

void    identify(Base *p)
{
    std::cout << "p: "; 
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    std::cout << "p: "; 
    try 
    {
        A& a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        B& b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        C& c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...)
    {
        std::cout << "Unknown type" << std::endl;
    }
}

int main()
{
    srand(time(0));
   
   Base* obj = generate();
   identify(obj);
   identify(*obj);
   delete obj;
   return 0;
    return (0);
}