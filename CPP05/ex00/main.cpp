#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat ok = Bureaucrat("OK", 39);
			std::cout << ok;
			Bureaucrat wrong = Bureaucrat("Wrong", 151);
			std::cout << wrong;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat ok = Bureaucrat();
			std::cout << ok;
			Bureaucrat wrong = Bureaucrat("Wrong", -8);
			std::cout << wrong;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat ok = Bureaucrat("OK", 2);
			std::cout << ok;
			ok.incrementGrade();
			std::cout << ok;
			ok.incrementGrade();
			std::cout << ok;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat ok = Bureaucrat("OK", 148);
			std::cout << ok;
			ok.decrementGrade();
			std::cout << ok;
			ok.decrementGrade();
			std::cout << ok;
			ok.decrementGrade();
			std::cout << ok;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
