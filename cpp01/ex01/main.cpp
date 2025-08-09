/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:49:12 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 13:35:16 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 7;
    Zombie *horde = zombieHorde(N, "bayak");
    
    for (int i = 0; i < N; i++)
    {
        std::cout << "zombie number: " << i << std::endl;
        horde[i].announce();
    }
    
    delete[] horde;

    return (0);
}