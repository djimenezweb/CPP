#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("Robotomy Request", "Robocop");
	std::cout << *rrf << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Terminator");
	std::cout << *rrf << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("unfathomable distortion", "Wall-E");
	std::cout << rrf << std::endl;
	delete rrf;

	return (0);
}
