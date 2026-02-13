#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() :
	name("undefined"),
	grade(GRADE_MIN)
{}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string set_name, int set_grade) :
	name(set_name.empty() ? "undefined" : set_name)
{
	if (set_grade < GRADE_MAX)
		throw GradeTooHighException();
	else if (set_grade > GRADE_MIN)
		throw GradeTooLowException();
	grade = set_grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name(other.name),
	grade(other.grade)
{}

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

// Increment grade
void Bureaucrat::incrementGrade()
{
	if (grade == GRADE_MAX)
		throw GradeTooHighException();
	grade--;
}

// Decrement grade
void Bureaucrat::decrementGrade()
{
	if (grade == GRADE_MIN)
		throw GradeTooLowException();
	grade++;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Bureaucrat &object)
{
	output << object.getName() << ", bureaucrat grade " << object.getGrade();
	return (output);
}

// Grade too high exception
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

// Grade too low exception
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// Sign form
void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
	{
		std::cout << "Form " << form.getName() << " is already signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed form " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << name << " couldn't sign form " << form.getName() << ": "
				  << e.what() << std::endl;
	}
}
