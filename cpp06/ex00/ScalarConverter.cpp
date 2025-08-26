/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:54:58 by odana             #+#    #+#             */
/*   Updated: 2025/08/26 14:16:57 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::DetectorFunc ScalarConverter::detectors[] =
{
    &ScalarConverter::isChar,
    &ScalarConverter::isInt,
    &ScalarConverter::isFloat,
    &ScalarConverter::isDouble
};

ScalarConverter::ConverterFunc ScalarConverter::converters[] =
{
    &ScalarConverter::convertChar,
    &ScalarConverter::convertInt,
    &ScalarConverter::convertFloat,
    &ScalarConverter::convertDouble
};

void ScalarConverter::convert(const std::string& str)
{
    for (int i = 0; i < 4; i++)
    {
        if (detectors[i](str))
        {
            converters[i](str);
            return;
        }
    }
    std::cout << "Error: Invalid input format" << std::endl;
}

bool ScalarConverter::isChar(const std::string& str)
{
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}


bool ScalarConverter::isInt(const std::string& str)
{
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;
    
    std::string result = str.substr(0, str.length() - 1);
    return (result.find('.') != std::string::npos && isValidNumber(result));
}

bool ScalarConverter::isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
        return true;
    
    return (str.find('.') != std::string::npos
            && str[str.length() - 1] != 'f'
            && isValidNumber(str));
}

bool ScalarConverter::isValidNumber(const std::string& str)
{
    if (str.empty()) return false;
    
    size_t start = 0;
    bool hasDecimal = false;
    
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    
    if (start >= str.length())
        return false;
    
    for (size_t i = start; i < str.length(); i++)
    {
        if (str[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void ScalarConverter::convertSpecial(const std::string& str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convertChar(const std::string& str)
{
    char c = str[1];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string& str)
{
    char* endptr;
    long l = strtol(str.c_str(), &endptr, 10);
    
    std::cout << "char: ";
    if (l < 0 || l > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(l)))
        std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (l < INT_MIN || l > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(l) << std::endl;
    
    std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff")
    {
        ScalarConverter::convertSpecial(str);
        return;
    }
    
    double f = atof(str.c_str());
    bool isWholeNumber = (f == static_cast<int>(f));
    
    std::cout << "char: ";
    if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else 
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    std::cout << "float: " << static_cast<float>(f);
    if (isWholeNumber)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    
    std::cout << "double: " << f;
    if (isWholeNumber)
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void ScalarConverter::convertDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf")
    {
        ScalarConverter::convertSpecial(str);
        return;
    }
    
    double d = atof(str.c_str());
    bool isWholeNumber = (d == static_cast<int>(d));
    
    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else 
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    
    std::cout << "float: " << static_cast<float>(d);
    if (isWholeNumber)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    
    std::cout << "double: " << d;
    if (isWholeNumber)
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

