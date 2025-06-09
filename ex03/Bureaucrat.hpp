#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Bureaucrat
{
private:
    enum
    {
        HIGHTESTGRADE = 1,
        LOWESTGRADE = 150
    };
    const std::string name;
    int grade;
    Bureaucrat();

public:
    Bureaucrat(std::string, int);

    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &rhs);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void decrement();
    void increment();
    void signAForm(AForm &f);
    void executeForm(AForm const &form) const;

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Bureaucrat::GradeTooLowException");
        }
    };

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Bureaucrat::GradeTooHighException");
        }
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &infile);

#endif
