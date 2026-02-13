#include "Form.hpp"

// Default constructor
Form::Form() :
	name("undefined"),
	is_signed(false),
	req_grade_sign(150),
	req_grade_exec(150)
{}

// Parameterized constructor
Form::Form(std::string name, int req_sign, int req_exec) :
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
Form::Form(const Form &other) :
	name(other.name),
	is_signed(other.is_signed),
	req_grade_sign(other.req_grade_sign),
	req_grade_exec(other.req_grade_exec)
{}

// Copy assignment operator overload
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return (*this);
}

// Destructor
Form::~Form() {}

// Return form `name`
std::string Form::getName() const
{
	return (name);
}

// Return form `is_signed`
bool Form::getIsSigned() const
{
	return (is_signed);
}

// Return form `req_grade_sign`
int Form::getReqGradeSign() const
{
	return (req_grade_sign);
}

// Return form `req_grade_exec`
int Form::getReqGradeExec() const
{
	return (req_grade_exec);
}

// Sign form if bureaucrat is allowed to
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > req_grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Form &form)
{
	output << "Form " << form.getName() << " "
		   << (form.getIsSigned() ? "(signed)" : "(not signed)")
		   << ". Required grades: " << form.getReqGradeSign() << " (sign), "
		   << form.getReqGradeExec() << " (exec)";
	return (output);
}

// Grade too high exception
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

// Grade too low exception
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
