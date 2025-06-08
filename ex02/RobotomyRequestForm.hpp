#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class RobotomyRequestForm : public AForm
{
private:
    enum
    {
        SIGNGRADE = 72,
        EXECGRADE = 45
    };
    std::string target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string formTarget);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
    ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const &executor) const;
    virtual std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &infile);

#endif
