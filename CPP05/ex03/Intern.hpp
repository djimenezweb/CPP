#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

struct Entry {
	std::string name;
	AForm* (*func)(std::string);
};

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string form_name, std::string target);
};

#endif
