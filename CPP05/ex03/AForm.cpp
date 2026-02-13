#include "AForm.hpp"

// Default constructor
AForm::AForm() :
	name("undefined"),
	is_signed(false),
	req_grade_sign(150),
	req_grade_exec(150)
{}

// Parameterized constructor
AForm::AForm(std::string name, int req_sign, int req_exec) :
	name(name.empty() ? "undefined" : name),
	is_signed(false),
	req_grade_sign(req_sign),
	req_grade_exec(req_exec)
{
	if (req_sign < GRADE_MAX || req_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (req_sign > GRADE_MIN || req_exec > GRADE_MIN)
		throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) :
	name(other.name),
	is_signed(other.is_signed),
	req_grade_sign(other.req_grade_sign),
	req_grade_exec(other.req_grade_exec)
{}

// Copy assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return (*this);
}

// Destructor
AForm::~AForm() {}

// Return form `name`
std::string AForm::getName() const
{
	return (name);
}

// Return form `is_signed`
bool AForm::getIsSigned() const
{
	return (is_signed);
}

// Return form `req_grade_sign`
int AForm::getReqGradeSign() const
{
	return (req_grade_sign);
}

// Return form `req_grade_exec`
int AForm::getReqGradeExec() const
{
	return (req_grade_exec);
}

// Sign form if bureaucrat is allowed to
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > req_grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}

// Check if bureaucrat is allowed to execute form
void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!is_signed)
		throw NotSignedException();
	else if (bureaucrat.getGrade() > req_grade_exec)
		throw GradeTooLowException();
	std::cout << bureaucrat.getName() << " executed " << name << std::endl;
	executeAction();
}

// Insertion operator overload (reference)
std::ostream &operator<<(std::ostream &output, const AForm &form)
{
	output << "Form " << form.getName() << " "
		   << (form.getIsSigned() ? "(signed)" : "(not signed)")
		   << ". Required grades: " << form.getReqGradeSign() << " (sign), "
		   << form.getReqGradeExec() << " (exec)";
	return (output);
}

// Insertion operator overload (pointer)
std::ostream &operator<<(std::ostream &output, const AForm *form)
{
	if (!form)
		return (output << "nullptr");
	return (output << *form);
}

// Grade too high exception
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

// Grade too low exception
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// Form is not signed exception
const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}
