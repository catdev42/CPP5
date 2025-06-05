#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Form
{
private:
    const std::string name;
    bool signedForm = 0;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form();
    Form(Form const &src);
    Form &operator=(Form const &rhs);
    ~Form();

    void beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Form::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Form::GradeTooLowException");
        }
    };
};

std::ostream &operator<<(std::ostream &o, Form const &infile);

#endif
