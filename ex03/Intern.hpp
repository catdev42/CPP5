#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Intern
{
private:

public:
    Intern();
    Intern(Intern const &src);
    Intern &operator=(Intern const &rhs);
    ~Intern();

    AForm *makeForm(std::string formType, std::string const &formTarget) const;
    class NonexistentFormException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Intern: NonexistentFormException");
        }
    };
};

#endif
