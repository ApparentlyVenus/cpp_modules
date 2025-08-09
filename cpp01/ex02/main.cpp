/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:40:34 by odana             #+#    #+#             */
/*   Updated: 2025/08/06 13:47:34 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string&	stringREF = brain;
	std::string*	stringPTR = &brain;

	std::cout << brain << " Address:" << &brain << std::endl;
	std::cout << stringREF << " Address held by stringREF:" << &stringREF << std::endl;
	std::cout << *stringPTR << " Address hedl by stingPTR:" << stringPTR << std::endl;
}