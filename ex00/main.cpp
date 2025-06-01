#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat man("ManMax", 42);
	std::cout << man << std::endl
			  << std::endl;
	try
	{
		Bureaucrat man2("Man2", 150);
		std::cout << man2 << std::endl
				  << std::endl;
		man2.decrement();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Caught High Grade Exception: " << e.what() << '\n';
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Caught Low Grade Exception: " << e.what() << '\n';
	}
	catch (const std::exception &e) // General catch for other std::exceptions
	{
		std::cerr << "Caught other std::exception: " << e.what() << '\n';
	}

	return 0;
}
