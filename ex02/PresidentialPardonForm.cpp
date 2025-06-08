#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Targetless PresPardonForm", SIGNGRADE, EXECGRADE), target("no target")
{
    std::cout << GREY << "PresidentialPardonForm default constructor" << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string formTarget) : AForm("PresidentialPardonForm", SIGNGRADE, EXECGRADE), target(formTarget)
{
    std::cout << GREY << "PresidentialPardonForm parametrized constructor" << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), SIGNGRADE, EXECGRADE), target(src.target)
{
    std::cout << GREY << "PresidentialPardonForm copy constructor" << RESET << std::endl;
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    std::cout << GREY << "PresidentialPardonForm copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        target = rhs.target;
        /*TODO MORE*/
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << GREY << "PresidentialPardonForm destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecGrade(executor);
    /***TODO EXECUTION DETAILS FOR SPECIFIC FORM***/
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &infile)
{
    o << "This form " << infile.getName()
      << " with target " << infile.getTarget()
      << ", gradeToSign = " << infile.getGradeToSign()
      << " and gradeToExecute = " << infile.getGradeToExecute()
      << " is ";
    if (infile.getSignedStatus())
        o << "signed";
    else
        o << "not signed";
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
