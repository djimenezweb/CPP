#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() {}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Copy assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.getGrade();
	}
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Return name
std::string Bureaucrat::getName() const
{
	return (name);
}

// Return grade
int Bureaucrat::getGrade() const
{
	return (grade);
}

// 1 is the highest, 150 is the lowest
void Bureaucrat::incrementGrade()
{

}

// 1 is the highest, 150 is the lowest
void Bureaucrat::decrementGrade()
{

}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Bureaucrat &other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (output);
}
