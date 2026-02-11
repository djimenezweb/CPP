#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 37), target("undefined")
{
	// 	to do!!!!!
}

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 37), target(target)
{
	std::ofstream ostream;
	std::string filename = target + "_shrubbery";
	ostream.open(filename.c_str());
	if (ostream.fail())
	{
		// to do!
	}
	// WRITE ASCII TREE
}

// Copy constructor NECESITAMOS LLAMAR AL CONSTRUCTOR DE AFORM???????????
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("Shrubbery Creation Form", 145, 37)
{
	// to do
	(void)other;
}

// Copy assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// Delete allocated memory
}

// Execute
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
