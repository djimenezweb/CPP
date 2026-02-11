#include "Intern.hpp"

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern &other)
{
	(void)other;
}

// Copy assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
Intern::~Intern()
{
	// Delete allocated memory
}

AForm *createA(std::string t)
{
	return (new ShrubberyCreationForm(t));
}

AForm *createB(std::string t)
{
	return (new RobotomyRequestForm(t));
}

AForm *createC(std::string t)
{
	return (new PresidentialPardonForm(t));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string name_arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*(*forms[3])(std::string) = { &createA, &createB, &createC };

	for (size_t i = 0; i < 3; i++)
	{
		if (form_name == name_arr[i])
			return (forms[i](target));
	}
	return (NULL);
}
