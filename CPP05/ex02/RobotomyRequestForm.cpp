#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", ROBOT_SIGN, ROBOT_EXEC),
	target("undefined")
{}

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", ROBOT_SIGN, ROBOT_EXEC),
	target(target)
{}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm("Robotomy Request Form", ROBOT_SIGN, ROBOT_EXEC),
	target(other.target)
{}

// Copy assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{}

// Execute
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << "TAC TAC TAC TAC" << std::endl;
		/* Makes some drilling noises, then informs that <target> has been robotomized
		successfully 50% of the time. Otherwise, it informs that the robotomy failed. */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
