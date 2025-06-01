#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("John Doe"), grade(LOWESTGRADE)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string givenName, int gradeStart) : name(givenName)
{
    std::cout << "Bureaucrat parametrized constructor" << std::endl;
    if (gradeStart < HIGHTESTGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (gradeStart > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    grade = gradeStart;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade)
{
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "Bureaucrat copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        grade = rhs.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decrement()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}
void Bureaucrat::increment()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Bureaucrat &infile)
{
    o << infile.getName() << ", bureaucrat grade " << infile.getGrade();
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
