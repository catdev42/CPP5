#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class ShrubberyCreationForm : public AForm
{
private:
    enum
    {
        SIGNGRADE = 145,
        EXECGRADE = 137
    };
    std::string target;
    ShrubberyCreationForm();
    void plantShurbs(std::ofstream &o) const;

public:
    ShrubberyCreationForm(std::string formTarget);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
    ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const &executor) const;
    virtual std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &infile);

#endif
