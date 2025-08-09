/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:49:49 by odana             #+#    #+#             */
/*   Updated: 2025/08/07 23:37:57 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

enum	Level {DEBUG, INFO, WARNING, ERROR, NOVAL};

class Harl
{
	private:
		
		Level	stringToLevel(std::string strLevel);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		void	complain(std::string strLevel);
};

#endif