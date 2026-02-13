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

// Clone Shrubbery Form
AForm *Intern::cloneShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Clone Robotomy Form
AForm *Intern::cloneRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

// Clone Presidential Form
AForm *Intern::clonePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

// String to lower case auxiliary function
std::string strtolower(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return (str);
}

// Return a pointer to a new form that matches `form_name`
AForm *Intern::makeForm(std::string form_name, std::string target)
{
	Entry arr[] = {
		{ "shrubbery creation", &Intern::cloneShrubbery },
		{ "robotomy request", &Intern::cloneRobotomy },
		{ "presidential pardon", &Intern::clonePresidential }
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (strtolower(form_name) == arr[i].name)
			return ( (this->*arr[i].func)(target) );
	}
	return (NULL);
}
