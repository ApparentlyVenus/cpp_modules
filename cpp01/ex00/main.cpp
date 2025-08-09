/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:32:43 by odana             #+#    #+#             */
/*   Updated: 2025/08/05 09:40:57 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "Stack Allocated Zombie:" << std::endl;
    randomChump("7mar");

    std::cout << "Heap Allocated Zombie" << std::endl;
    Zombie *heapZombie = newZombie("ba8el");
    heapZombie->announce();
    delete heapZombie;

    return (0);
}