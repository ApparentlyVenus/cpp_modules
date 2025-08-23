/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:12:13 by odana             #+#    #+#             */
/*   Updated: 2025/08/19 11:11:11 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
    private:

        const std::string   name;
        bool                isSigned;
        const int           gradeRequiredSign;
        const int           gradeRequiredExecute;
        
    public:
    
        Form();
        Form(const std::string& name,
            const int gradeRequiredSign,
            const int gradeRequiredExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getGradeRequiredSign() const;
        int                 getGradeRequiredExecute() const;
        
        void    beSigned(const Bureaucrat& bureaucrat);

        class   GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


std::ostream& operator<<(std::ostream& out, const Form& form);

#endif