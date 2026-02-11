#include "AForm.hpp"

// Default constructor
AForm::AForm() : name("undefined"), is_signed(false), req_grade_sign(150), req_grade_exec(150)
{

}

// Parameterized constructor
AForm::AForm(std::string name, int req_sign, int req_exec) : name(name), is_signed(false), req_grade_sign(req_sign), req_grade_exec(req_exec)
{
	if (req_sign < GRADE_MAX || req_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (req_sign > GRADE_MIN || req_exec > GRADE_MIN)
		throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), req_grade_sign(other.req_grade_sign), req_grade_exec(other.req_grade_exec){}

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
AForm::~AForm()
{
	// Delete allocated memory
}

// Getters
std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (is_signed);
}

int AForm::getReqGradeSign() const
{
	return (req_grade_sign);
}

int AForm::getReqGradeExec() const
{
	return (req_grade_exec);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > req_grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed)
		throw NotSignedException();
	else if (executor.getGrade() > req_grade_exec)
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << name << std::endl;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const AForm &form)
{
	output << "Form " << form.getName() << " "
		   << (form.getIsSigned() ? "(signed)" : "(not signed)")
		   << ". Required grades: " << form.getReqGradeSign() << " (sign), "
		   << form.getReqGradeExec() << " (exec)";
	return (output);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}
