#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

AForm *tryMakeForm(Intern &intern, std::string formType, std::string const &formTarget)
{
	AForm *form = NULL;
	try
	{
		form = intern.makeForm(formType, formTarget);
	}
	catch (std::bad_alloc)
	{
		std::exit(EXIT_FAILURE);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return form;
}

int main()
{
	srand(time(0));
	AForm *form = NULL;

	Bureaucrat man("ManMax", 42);
	Intern intern;
	std::cout << man << std::endl
			  << std::endl;

	form = tryMakeForm(intern, "presidentialpardon", "dobbie");
	man.signAForm(*form);
	man.executeForm(*form);
	delete form;

	form = tryMakeForm(intern, "shrubbery", "office");
	man.signAForm(*form);
	man.executeForm(*form);
	delete form;

	form = tryMakeForm(intern, "robotomy", "office");
	man.signAForm(*form);
	man.executeForm(*form);
	man.executeForm(*form);
	man.executeForm(*form);
	man.executeForm(*form);

	form = tryMakeForm(intern, "someform", "office");

	return 0;
}
