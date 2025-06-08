#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : name("Unnamed"), signedForm(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << GREY << "Form default constructor" << RESET << std::endl;
    return;
}

Form::Form(std::string formName, int signGrade, int executeGrade) : name(formName), signedForm(false), gradeToSign(signGrade), gradeToExecute(executeGrade)
{
    std::cout << GREY << "Form parametrized constructor" << RESET << std::endl;
    if (gradeToSign < HIGHTESTGRADE || gradeToExecute < HIGHTESTGRADE)
        throw GradeTooHighException();
    if (gradeToSign > LOWESTGRADE || gradeToExecute > LOWESTGRADE)
        throw GradeTooLowException();
}

Form::Form(Form const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << GREY << "Form copy constructor" << RESET << std::endl;
    return;
}

Form &Form::operator=(Form const &rhs)
{
    std::cout << GREY << "Form copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        /*This will not do anything at the moment as the values are const*/;
    }
    return *this;
}

Form::~Form()
{
    std::cout << GREY << "Form destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

std::string Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getSignedStatus() const
{
    return this->signedForm;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() < this->getGradeToSign())
        this->signedForm = true;
    else
        throw GradeTooLowException();
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Form &infile)
{
    o << "Form " << infile.getName()
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
