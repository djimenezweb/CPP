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
void RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const
{
	try
	{
		validateExecution(bureaucrat);
		std::cout << "* TAC * TAC * TAC * TAC *" << std::endl;
		srand(time(0));
		int random_number = rand();
		if (random_number % 2 == 0)
			std::cout << target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy has failed. " << target << " couldn't be robotomized" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
