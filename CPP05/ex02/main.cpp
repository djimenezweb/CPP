#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat fidelio = Bureaucrat("Fidelio", 2);
	Bureaucrat simplicio = Bureaucrat("Simplicio", 71);
	Bureaucrat perfidio = Bureaucrat("Perfidio", 147);

	ShrubberyCreationForm shrub_form = ShrubberyCreationForm("target1");
	RobotomyRequestForm rob_form = RobotomyRequestForm("target2");
	PresidentialPardonForm pres_form = PresidentialPardonForm("target3");

	std::cout << shrub_form << std::endl;
	std::cout << rob_form << std::endl;
	std::cout << pres_form << std::endl;

	std::cout << std::endl << "SHRUBBERY CREATION FORM" << std::endl;
	fidelio.executeForm(shrub_form);
	simplicio.signForm(shrub_form);
	fidelio.executeForm(shrub_form);
	
	std::cout << std::endl << "ROBOTOMY REQUEST FORM" << std::endl;
	simplicio.signForm(rob_form);
	simplicio.executeForm(rob_form);
	fidelio.executeForm(rob_form);

	std::cout << std::endl << "PRESIDENTIAL PARDON FORM" << std::endl;
	simplicio.signForm(pres_form);
	fidelio.executeForm(pres_form);
	fidelio.signForm(pres_form);
	fidelio.executeForm(pres_form);

	return (0);
}
