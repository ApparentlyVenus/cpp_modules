/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:28:47 by odana             #+#    #+#             */
/*   Updated: 2025/09/01 13:56:10 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) { (void)other; }

RPN&    RPN::operator=(const RPN& other) 
{ 
    (void)other;
    return (*this); 
}

RPN::~RPN() {}

std::string RPN::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return ("");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (str.substr(start, end - start + 1));
}

bool    RPN::isOperator(const std::string& token)
{
    return (token == "*" || token == "/" || token == "+" || token == "-");
}

bool    RPN::isValidNumber(const std::string& token)
{
    if (token.empty())
        return (false);
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!std::isdigit(token[i]))
            return (false);
    }
    if (token.length() != 1)
        return (false);
    return (true);
}

int RPN::performOperation(int operand1, int operand2, const std::string& op)
{
    if (op == "+")
        return operand1 + operand2;
    else if (op == "-")
        return operand1 - operand2;
    else if (op == "*")
        return operand1 * operand2;
    else if (op == "/") {
        if (operand2 == 0)
            throw std::runtime_error("Error");
        return operand1 / operand2;
    }
    throw std::runtime_error("Error");
}

int RPN::calculate(const std::string& input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        token = trim(token);
        if (isValidNumber(token))
        {
            int num = std::atoi(token.c_str());
            _stack.push(num);
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            int operand2 = _stack.top();
            _stack.pop();
            int operand1 = _stack.top();
            _stack.pop();

            int result = performOperation(operand1, operand2, token);
            _stack.push(result);
        }
        else
            throw std::runtime_error("Error");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return (_stack.top());
}