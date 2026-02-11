#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", SHRUB_SIGN, SHRUB_EXEC),
	target("undefined")
{}

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", SHRUB_SIGN, SHRUB_EXEC),
	target(target)
{}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm("Shrubbery Creation Form", SHRUB_SIGN, SHRUB_EXEC),
	target(other.target)
{}

// Copy assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// Execute
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::ofstream ostream;
		std::string filename = target + "_shrubbery";
		ostream.open(filename.c_str());
		if (!ostream.fail())
		{
			ostream << ASCII_ART_TREE;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
