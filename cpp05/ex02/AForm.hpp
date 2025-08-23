/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:12:13 by odana             #+#    #+#             */
/*   Updated: 2025/08/21 03:19:39 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
    private:

        const std::string   name;
        bool                isSigned;
        const int           gradeRequiredSign;
        const int           gradeRequiredExecute;
        
    public:
    
        AForm();
        AForm(const std::string& name,
            const int gradeRequiredSign,
            const int gradeRequiredExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getGradeRequiredSign() const;
        int                 getGradeRequiredExecute() const;
        
        void            beSigned(const Bureaucrat& bureaucrat);
        virtual void    execute(const Bureaucrat& bureaucrat) const = 0;
        
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
        class   FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif