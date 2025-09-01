/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:28:50 by odana             #+#    #+#             */
/*   Updated: 2025/09/01 13:55:54 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <exception>
# include <cstdlib>

class RPN
{
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
    
private:
    std::stack<int> _stack;
    
    std::string trim(const std::string& str);
    bool    isOperator(const std::string& token);
    bool    isValidNumber(const std::string& token);
    int     performOperation(int operand1, int operand2, const std::string& op);
};

#endif