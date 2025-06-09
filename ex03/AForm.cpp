#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : name("Unnamed"), signedAForm(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << GREY << "AForm default constructor" << RESET << std::endl;
    return;
}

AForm::AForm(std::string AFormName, int signGrade, int executeGrade) : name(AFormName), signedAForm(false), gradeToSign(signGrade), gradeToExecute(executeGrade)
{
    std::cout << GREY << "AForm parametrized constructor" << RESET << std::endl;
    if (gradeToSign < HIGHTESTGRADE || gradeToExecute < HIGHTESTGRADE)
        throw GradeTooHighException();
    if (gradeToSign > LOWESTGRADE || gradeToExecute > LOWESTGRADE)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << GREY << "AForm copy constructor" << RESET << std::endl;
    return;
}

AForm &AForm::operator=(AForm const &rhs)
{
    std::cout << GREY << "AForm copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        /*This will not do anything at the moment as the values are const*/;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << GREY << "AForm destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getSignedStatus() const
{
    return this->signedAForm;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() < this->getGradeToSign())
        this->signedAForm = true;
    else
        throw GradeTooLowException();
}

void AForm::checkExecGrade(Bureaucrat const &b) const
{
    if (b.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    if (!this->signedAForm)
        throw FormUnsignedException();
    else
        return;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const AForm &infile)
{
    o << "AForm " << infile.getName()
      << " with gradeToSign = " << infile.getGradeToSign()
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
