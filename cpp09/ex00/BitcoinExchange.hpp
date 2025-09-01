/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:49:00 by odana             #+#    #+#             */
/*   Updated: 2025/09/01 13:05:33 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <exception>
# include <cstdlib>
# include <limits.h>

class BitcoinExchange
{
public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange&    operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool    loadDatabase(const std::string& dbFile);
    void    processInputFile(const std::string& inputFile);
    
private:

    std::map<std::string, double>   _priceDB;

    std::string trim(const std::string& str);
    double  getExchangeRate(const std::string& date);
    bool    isValidDate(const std::string& date);
};

#endif