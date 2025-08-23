/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:12:15 by odana             #+#    #+#             */
/*   Updated: 2025/08/19 11:10:50 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
:   name("Default"),
    isSigned(false),
    gradeRequiredSign(150),
    gradeRequiredExecute(150) {}

Form::Form(const std::string& name, const int gradeRequiredSign, const int gradeRequiredExecute)
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

Form::Form(const Form& other)
:   name(other.name), isSigned(other.isSigned),
    gradeRequiredSign(other.gradeRequiredSign), 
    gradeRequiredExecute(other.gradeRequiredExecute) {}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeRequiredSign() const
{
    return this->gradeRequiredSign;
}

int Form::getGradeRequiredExecute() const
{
    return this->gradeRequiredExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeRequiredSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! (minimum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << form.getGradeRequiredSign()
        << ", execute grade: " << form.getGradeRequiredExecute();
    return out;
}