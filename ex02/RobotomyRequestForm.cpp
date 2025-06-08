#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Targetless RobotomyRequestForm", SIGNGRADE, EXECGRADE), target("no target")
{
    std::cout << GREY << "RobotomyRequestForm default constructor" << RESET << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string formTarget) : AForm("RobotomyRequestForm", SIGNGRADE, EXECGRADE), target(formTarget)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), SIGNGRADE, EXECGRADE), target(src.getTarget())
{
    std::cout << GREY << "RobotomyRequestForm copy constructor" << RESET << std::endl;
    /*TODO*/;
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    std::cout << GREY << "RobotomyRequestForm copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        target = rhs.target;
        /*TODO*/;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << GREY << "RobotomyRequestForm destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecGrade(executor);
    /***TODO EXECUTION DETAILS FOR SPECIFIC FORM***/
    std::cout << "Brrrr rrr brrrrr" << std::endl;
    int randomNum = rand() % 2;
    if (randomNum == 0)
    {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &infile)
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
