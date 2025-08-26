/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:04:02 by odana             #+#    #+#             */
/*   Updated: 2025/08/26 14:44:39 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string> 

struct Data
{
    int         id;
    std::string str;
    double      val;

    Data(int id, const std::string& str, double val);
};

#endif