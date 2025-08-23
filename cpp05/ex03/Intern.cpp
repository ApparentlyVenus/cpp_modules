/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:43:32 by odana             #+#    #+#             */
/*   Updated: 2025/08/23 19:03:44 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    formCreators[0] = &Intern::createShrubberyCreationForm;
    formCreators[1] = &Intern::createRobotomyRequestForm;
    formCreators[2] = &Intern::createPresidentialPardonForm;
    
    formNames[0] = "shrubbery creation";
    formNames[1] = "robotomy request";
    formNames[2] = "presidential pardon";
}

Intern::Intern(const Intern& other)
{
    for (int i = 0; i < 3; i++)
    {
        formCreators[i] = other.formCreators[i];
        formNames[i] = other.formNames[i];
    }
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            formCreators[i] = other.formCreators[i];
            formNames[i] = other.formNames[i];
        }
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*formCreators[i])(target));
        }
    }
    std::cout << "Error: Form name \"" << formName << "\" does not exist" << std::endl;
    return (NULL);
}