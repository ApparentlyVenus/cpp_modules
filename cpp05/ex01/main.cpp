/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:03:56 by odana             #+#    #+#             */
/*   Updated: 2025/08/19 11:37:19 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form validForm("Daftar Siyara", 50, 25);
        std::cout << validForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        Form invalidForm("Daftar Moto", 0, 25);
		std::cout << invalidForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }    
    try
    {
        Form form("Rokhsit Swe2 Siyara", 75, 50);
        Bureaucrat goodBureaucrat("Wael Asmar", 50);
        Bureaucrat badBureaucrat("Yousef Itani", 100);
        
        std::cout << form << std::endl;
        std::cout << goodBureaucrat << std::endl;
        std::cout << badBureaucrat << std::endl;
        
        goodBureaucrat.signForm(form);
        std::cout << form << std::endl;
        
        badBureaucrat.signForm(form);
        
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }    
    try
    {
        Form strictForm("Rokhsit Swe2a moto", 1, 1);
        Bureaucrat almostBoss("Lynn Yousef", 2);
        Bureaucrat theBoss("Mhamad Abou Ahmad", 1);
        
        almostBoss.signForm(strictForm);
        theBoss.signForm(strictForm);
        
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}