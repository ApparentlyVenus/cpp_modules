/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 03:21:47 by odana             #+#    #+#             */
/*   Updated: 2025/08/23 18:50:28 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Intern Test ===" << std::endl;

    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* form1 = intern.makeForm("shrubbery creation", "garden");
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    AForm* form3 = intern.makeForm("presidential pardon", "Arthur");

    AForm* form4 = intern.makeForm("coffee making", "kitchen");

    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    return (0);
}