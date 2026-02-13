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
void PresidentialPardonForm::executeAction() const
{
	try
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
