#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Targetless ShrubberyRequestForm", SIGNGRADE, EXECGRADE), target("no target")
{
    std::cout << GREY << "ShrubberyCreationForm default constructor" << RESET << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string formTarget) : AForm("ShrubberyRequestForm", SIGNGRADE, EXECGRADE), target(formTarget)
{
    std::cout << GREY << "ShrubberyCreationForm parametrized constructor" << RESET << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), SIGNGRADE, EXECGRADE), target(src.getTarget())
{
    std::cout << GREY << "ShrubberyCreationForm copy constructor" << RESET << std::endl;
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    std::cout << GREY << "ShrubberyCreationForm copy assignment operator" << RESET << std::endl;
    if (this != &rhs)
    {
        target = rhs.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << GREY << "ShrubberyCreationForm destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecGrade(executor);
    std::string outfileName = this->getTarget() + "_shrubbery";
    std::ofstream outfile(outfileName.c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Runtime Error: Could not open file " + outfileName + " for writing");
    plantShurbs(outfile);
    if (!outfile.good())
    {
        outfile.close();
        throw std::runtime_error("Runtime Error: Could write tp file " + outfileName);
    }
    outfile.close();
    std::cout << "Shrubbery has been planted in " << outfileName << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &infile)
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

void ShrubberyCreationForm::plantShurbs(std::ofstream &outfile) const
{
    outfile << "               ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    outfile << std::endl;
    outfile << "         ccee88oo" << std::endl;
    outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
    outfile << " dOB69QO8PdUOpugoO9bD" << std::endl;
    outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    outfile << "    6OuU  /p u gcoUodpP" << std::endl;
    outfile << "      \\\\//  /douUP" << std::endl;
    outfile << "        \\\\////" << std::endl;
    outfile << "         |||/\\" << std::endl;
    outfile << "         |||\\/" << std::endl;
    outfile << "         |||||" << std::endl;
    outfile << "   .....//||||\\...." << std::endl;
    outfile << std::endl;
}
