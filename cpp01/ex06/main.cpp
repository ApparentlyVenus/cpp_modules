/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:11:41 by odana             #+#    #+#             */
/*   Updated: 2025/08/07 23:21:19 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect format: ./harl <input>" << std::endl;
		return (1);
	}

	std::string	input = argv[1];
	Harl harl;
	harl.complain(input);
	return (0);
}
