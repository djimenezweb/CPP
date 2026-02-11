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

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string name_arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form_arr[3] = {&ShrubberyCreationForm(), &RobotomyRequestForm(), &PresidentialPardonForm()};

	for (size_t i = 0; i < 3; i++)
	{
		if (form_name == name_arr[i])
			return (new form_arr[i]);
	}
	return (NULL);
}
