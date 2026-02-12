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

AForm *cloneShrubbery(std::string t)
{
	return (new ShrubberyCreationForm(t));
}

AForm *cloneRobotomy(std::string t)
{
	return (new RobotomyRequestForm(t));
}

AForm *clonePresidential(std::string t)
{
	return (new PresidentialPardonForm(t));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	Entry arr[] = {
		{ "shrubbery creation", cloneShrubbery },
		{ "robotomy request", cloneRobotomy },
		{ "presidential pardon", clonePresidential }
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (form_name == arr[i].name)
			return (arr[i].func(target));
	}
	return (NULL);
}
