#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("undefined"), grade(GRADE_MIN) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string set_name, int set_grade) : name(set_name)
{
	if (set_grade < GRADE_MAX)
		throw GradeTooHighException();
	else if (set_grade > GRADE_MIN)
		throw GradeTooLowException();
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

// Sign form
void Bureaucrat::signForm(AForm &form)
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
		std::cerr << name << " couldn't sign form " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Bureaucrat &other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (output);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
