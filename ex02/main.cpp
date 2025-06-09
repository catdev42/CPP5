#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

int main()
{
	srand(time(0));

	Bureaucrat man("ManMax", 42);
	std::cout << man << std::endl
			  << std::endl;
	PresidentialPardonForm presForm("Dobbie");
	man.signAForm(presForm);
	man.executeForm(presForm);
	ShrubberyCreationForm shrubForm("house");
	// man.signAForm(shrubForm);
	man.executeForm(shrubForm);

	RobotomyRequestForm roboForm("Flower");
	man.signAForm(roboForm);
	man.executeForm(roboForm);
	man.executeForm(roboForm);
	man.executeForm(roboForm);
	man.executeForm(roboForm);
	return 0;
}
