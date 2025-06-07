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
    Form();

public:
    Form(std::string formName, int signGrade = 1, int executeGrade = 1);
    Form(Form const &src);
    Form &operator=(Form const &rhs);
    ~Form();

    std::string getName() const;
    int getGradeToSign() const;
    int getSignedStatus() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Form::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Form::GradeTooLowException");
        }
    };
};

std::ostream &operator<<(std::ostream &o, Form const &infile);

#endif
