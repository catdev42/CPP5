#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class PresidentialPardonForm : public AForm
{
private:
    enum
    {
        SIGNGRADE = 25,
        EXECGRADE = 5
    };
    std::string target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string formTarget);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
    ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const & executor) const ;
    virtual std::string getTarget() const;
};
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &infile);

#endif
