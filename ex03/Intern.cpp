#include "Intern.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << GREY << "Intern default constructor" << RESET << std::endl;
    return;
}

Intern::Intern(Intern const &src)
{
    std::cout << GREY << "Intern copy constructor" << RESET << std::endl;
    (void)src;
    return;
}

Intern &Intern::operator=(Intern const &rhs)
{
    std::cout << GREY << "Intern copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        /*TODO*/;
    }
    return *this;
}

Intern::~Intern()
{
    std::cout << GREY << "Intern destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

static void makeLower(std::string &str)
{
    for (std::string::iterator it = str.begin(); it < str.end(); it++)
        *it = static_cast<char>(std::tolower(static_cast<unsigned char>(*it)));
    return;
}

AForm *Intern::makeForm(std::string formType, std::string const &formTarget) const
{
    int i = 0;
    std::string forms[] = {"shrubbery", "robotomy", "presidentialpardon"};
    makeLower(formType);
    int numForms = sizeof(forms) / sizeof(forms[0]);

    while (i < numForms)
    {
        if (formType.find(forms[i]) != std::string::npos)
            break;
        i++;
    }

    switch (i)
    {
    case 0:
        std::cout << "Intern creates ShrubberyCreationForm targetted at " << formTarget << std::endl;
        return new ShrubberyCreationForm(formTarget);
    case 1:
        std::cout << "Intern creates RobotomyRequestForm targetted at " << formTarget << std::endl;
        return new RobotomyRequestForm(formTarget);
    case 2:
        std::cout << "Intern creates PresidentialPardonForm targetted at " << formTarget << std::endl;
        return new PresidentialPardonForm(formTarget);
    default:
        throw NonexistentFormException();
    }
}

/********************************************/
/********************************************/
/****** STREAM ******/

/********************************************/
/********************************************/
/****** PRIVATE ******/
