#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	fidelio = Bureaucrat("Fidelio", 39);
	Bureaucrat	perfidio = Bureaucrat("Perfidio", 146);
	Form		form = Form("CE-19b", 80, 10);
	
	std::cout << fidelio << std::endl
			  << perfidio << std::endl
			  << form << std::endl << std::endl;

	perfidio.signForm(form);
	std::cout << form << std::endl;
	fidelio.signForm(form);
	std::cout << form << std::endl;
	perfidio.signForm(form);

	return (0);
}
