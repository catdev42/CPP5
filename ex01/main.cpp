#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat man("ManMax", 42);
	std::cout << man << std::endl
			  << std::endl;
	Form form21("Form 21", 50, 5);
	man.signForm(form21);

	Bureaucrat man2("ManJoe", 42);
	std::cout << man2 << std::endl
			  << std::endl;
	Form form22("Form 22", 10, 5);
	man2.signForm(form22);
	return 0;
}
