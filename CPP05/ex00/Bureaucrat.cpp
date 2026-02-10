#include "Bureaucrat.hpp"
#include <exception>

// Default constructor
Bureaucrat::Bureaucrat() {}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string set_name, int set_grade) : name(set_name)
{
	if (set_grade < GRADE_MAX)
		GradeTooHighException();
	else if (set_grade > GRADE_MIN)
		GradeTooLowException();
	grade = set_grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Copy assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
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
	if (grade == GRADE_MAX)
		throw GradeTooHighException();
	grade--;
}

// 1 is the highest, 150 is the lowest
void Bureaucrat::decrementGrade()
{
	if (grade == GRADE_MIN)
		throw GradeTooLowException();
	grade++;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Bureaucrat &other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (output);
}
