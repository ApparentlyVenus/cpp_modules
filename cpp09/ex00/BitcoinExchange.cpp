/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:56:00 by odana             #+#    #+#             */
/*   Updated: 2025/09/01 13:20:15 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _priceDB(other._priceDB) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _priceDB = other._priceDB;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool    BitcoinExchange::loadDatabase(const std::string& dbFile)
{
    std::ifstream   file(dbFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("DB ERROR: Unable to open file");
    std::string line;
    bool    isFirstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue ;
        if (isFirstLine)
        {
            size_t  commaPos = line.find(",");
            if (commaPos == std::string::npos)
                throw std::runtime_error("DB ERROR: Invalid header");
            std::string date = line.substr(0, commaPos);
            std::string exchangeRate = line.substr(commaPos + 1);
            if (date != "date" || exchangeRate != "exchange_rate")
                throw std::runtime_error("DB ERROR: Invalid header");
            isFirstLine = false;
            continue ;
        }
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            std::cout << "DB ERROR: invalid format on line " << line << std::endl;
            continue ;
        }
        std::string date = trim(line.substr(0, commaPos));
        if (!isValidDate(date))
        {
            std::cout << "DB ERROR: invalid date on line " << line << std::endl;
            continue ;
        }
        std::string value = trim(line.substr(commaPos + 1));
        std::istringstream iss(value);
        double price;
        if (!(iss >> price))
        {
            std::cout << "DB ERROR: invalid price format on line " << line << std::endl;
            continue ;
        }
        if (!iss.eof())
        {
            std::cout << "DB ERROR: extra characters after price on line " << line << std::endl;
            continue ;
        }
        _priceDB[date] = price;
    }
    file.close();
    return (true);
}

void BitcoinExchange::processInputFile(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Unable to open file");
    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue ;
        if (isFirstLine)
        {
            size_t  pipePos = line.find("|");
            if (pipePos == std::string::npos)
                throw std::runtime_error("Error: invalid header");
            std::string date = trim(line.substr(0, pipePos));
            std::string value = trim(line.substr(pipePos + 1));
            if (date != "date" || value != "value")
                throw std::runtime_error("Error: invalid header");
            isFirstLine = false;
            continue ;
        }
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = trim(line.substr(0, pipePos));
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string value = trim(line.substr(pipePos + 1));
        std::istringstream iss(value);
        double bitcoin;
        if (!(iss >> bitcoin))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (!iss.eof())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (bitcoin <= 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }
        if (bitcoin > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }
        double rate = getExchangeRate(date);
        if (rate < 0)
        {
            std::cout << "Error: no exchange rate available." << std::endl;
            continue ;
        }
        double result = bitcoin * rate;
        std::cout << date << " => " << bitcoin << " = " << result << std::endl;
    }
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _priceDB.find(date);
    if (it != _priceDB.end())
        return (it->second);
    std::map<std::string, double>::iterator lower = _priceDB.lower_bound(date);
    if (lower == _priceDB.begin())
        return (-1);
    --lower;
    return (lower->second);
}

bool    BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue ;
        if (!std::isdigit(date[i]))
            return (false);
    }
    size_t firstDash = date.find_first_of("-");
    size_t lastDash = date.find_last_of("-");
    std::string yearStr = date.substr(0, firstDash);
    std::string monthStr = date.substr(firstDash + 1, 2);
    std::string dayStr = date.substr(lastDash + 1, 2);
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    if (year < 0 || year > 9999 
        || month < 1 || month > 12 
        || day < 1 || day > 31)
        return (false);
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day < 1 || day > 29)
                return (false);
        }
        else if (day < 1 || day > 28)
            return (false);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    return (true);
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return ("");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (str.substr(start, end - start + 1));
}


