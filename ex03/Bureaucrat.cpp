#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("John Doe"), grade(LOWESTGRADE)
{
    std::cout << GREY << "Bureaucrat default constructor" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string givenName, int gradeStart) : name(givenName)
{
    std::cout << GREY << "Bureaucrat parametrized constructor" << RESET << std::endl;
    if (gradeStart < HIGHTESTGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (gradeStart > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    grade = gradeStart;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade)
{
    std::cout << GREY << "Bureaucrat copy constructor" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << GREY << "Bureaucrat copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        grade = rhs.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << GREY << "Bureaucrat destructor" << RESET << std::endl;
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

void Bureaucrat::signAForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->name << " signed AForm " << f.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign AForm " << f.getName()
                  << " because their grade (" << this->getGrade()
                  << ") is too low for the AForm requirement (" << f.getGradeToSign() << "): " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName()
                  << " due to an unexpected issue: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't execute form " << form.getName()
                  << " because their grade (" << this->getGrade()
                  << ") is too low for the AForm requirement (" << form.getGradeToExecute() << "): " << e.what() << std::endl;
    }
       catch (const AForm::FormUnsignedException &e)
    {
        std::cout << this->getName() << " couldn't execute form " << form.getName()
                  << " because the form is not signed: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " due to an unexpected issue: " << e.what() << std::endl;
    }
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
