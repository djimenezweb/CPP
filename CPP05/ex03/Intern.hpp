#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		struct Entry {
			std::string name;
			AForm* (Intern::*func)(std::string);
		};

		AForm *cloneShrubbery(std::string target);
		AForm *cloneRobotomy(std::string target);
		AForm *clonePresidential(std::string target);

		AForm *makeForm(std::string form_name, std::string target);
};

#endif
