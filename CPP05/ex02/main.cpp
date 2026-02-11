#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat fidelio = Bureaucrat("Fidelio", 2);

	ShrubberyCreationForm shrub_form = ShrubberyCreationForm("target1");
	PresidentialPardonForm pres_form = PresidentialPardonForm("target2");

	std::cout << "SHRUBBERY CREATION FORM" << std::endl;
	fidelio.executeForm(shrub_form);
	fidelio.signForm(shrub_form);
	fidelio.executeForm(shrub_form);

	std::cout << std::endl << "PRESIDENTIAL PARDON FORM" << std::endl;
	fidelio.signForm(pres_form);
	fidelio.executeForm(pres_form);

	// std::cout << std::endl << "ROBOTOMY REQUEST FORM" << std::endl;

	return (0);
}
