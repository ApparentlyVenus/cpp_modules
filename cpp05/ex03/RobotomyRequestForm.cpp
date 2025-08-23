/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:33:32 by odana             #+#    #+#             */
/*   Updated: 2025/08/21 03:07:34 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Default Robotomy Form", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Getter
const std::string& RobotomyRequestForm::getTarget() const
{
    return this->target;
}

// Execute implementation with 50/50 success rate
void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getGradeRequiredExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << "* BZZZZZZT * DRILLING NOISES * BZZZZZZT *" << std::endl;
    
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int random = std::rand() % 2;
    if (random == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomy failed on " << this->target << "!" << std::endl;
}