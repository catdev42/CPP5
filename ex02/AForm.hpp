#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif


class Bureaucrat;
class AForm
{
private:
    enum
    {
        HIGHTESTGRADE = 1,
        LOWESTGRADE = 150
    };
    const std::string name;
    bool signedAForm;
    const int gradeToSign;
    const int gradeToExecute;
    AForm();

public:
    AForm(std::string AFormName, int signGrade = 1, int executeGrade = 1);
    AForm(AForm const &src);
    AForm &operator=(AForm const &rhs);
    ~AForm();

    std::string getName() const;
    int getGradeToSign() const;
    int getSignedStatus() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &b);
    void checkExecGrade(Bureaucrat const &b) const;
    virtual void execute(Bureaucrat const &executor) const = 0;
    virtual std::string getTarget() const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("AForm::GradeTooHighException");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("AForm::GradeTooLowException");
        }
    };

    class FormUnsignedException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("AForm::FormUnsignedException thrown");
        }
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &infile);

#endif
