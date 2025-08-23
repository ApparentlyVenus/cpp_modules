/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:12:15 by odana             #+#    #+#             */
/*   Updated: 2025/08/21 03:05:40 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
:   name("Default"),
    isSigned(false),
    gradeRequiredSign(150),
    gradeRequiredExecute(150) {}

AForm::AForm(const std::string& name, const int gradeRequiredSign, const int gradeRequiredExecute)
:   name(name),
    isSigned(false),
    gradeRequiredSign(gradeRequiredSign),
    gradeRequiredExecute(gradeRequiredExecute)
{
    if (gradeRequiredExecute < 1 || gradeRequiredSign < 1)
        throw GradeTooHighException();
    if (gradeRequiredExecute > 150 || gradeRequiredSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
:   name(other.name), isSigned(other.isSigned),
    gradeRequiredSign(other.gradeRequiredSign), 
    gradeRequiredExecute(other.gradeRequiredExecute) {}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeRequiredSign() const
{
    return this->gradeRequiredSign;
}

int AForm::getGradeRequiredExecute() const
{
    return this->gradeRequiredExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeRequiredSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! (minimum grade is 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! (maximum grade is 150)";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form must be signed to be executed";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << form.getGradeRequiredSign()
        << ", execute grade: " << form.getGradeRequiredExecute();
    return out;
}