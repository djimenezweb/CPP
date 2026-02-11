#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", PRES_SIGN, PRES_EXEC),
	target("undefined")
{}

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", PRES_SIGN, PRES_EXEC),
	target(target)
{}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm("Presidential Pardon Form", PRES_SIGN, PRES_EXEC),
	target(other.target)
{}

// Copy assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{}

// Execute
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
