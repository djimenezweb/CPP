#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat fidelio = Bureaucrat("Fidelio", 2);

	ShrubberyCreationForm shrub_form = ShrubberyCreationForm("28B");

	fidelio.executeForm(shrub_form);
	fidelio.signForm(shrub_form);
	fidelio.executeForm(shrub_form);

	return (0);
}
