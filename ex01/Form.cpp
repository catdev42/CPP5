#include "Form.hpp"
#include <iostream>

Form::Form()
{
    std::cout << "Form default constructor" << std::endl;
    return;
}

Form::Form(Form const &src)
{
    std::cout << "Form copy constructor" << std::endl;
    /*TODO*/;
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

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Form &infile)
{
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
