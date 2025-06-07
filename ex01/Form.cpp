#include "Form.hpp"
#include <iostream>

Form::Form() : name("Unnamed"), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Form default constructor" << std::endl;
    return;
}

Form::Form(std::string formName, int signGrade, int executeGrade) : name(formName), gradeToSign(signGrade), gradeToExecute(executeGrade)
{
}

Form::Form(Form const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "Form copy constructor" << std::endl;
    return;
}

Form &Form::operator=(Form const &rhs)
{
    std::cout << "Form copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        /*TODO*/;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

std::string Form::getName() const {}
int Form::getGradeToSign() const {}
int Form::getSignedStatus() const {}
int Form::getGradeToExecute() const {}
void Form::beSigned(Bureaucrat &b) {}

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
