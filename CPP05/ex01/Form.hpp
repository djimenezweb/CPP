#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			req_grade_sign;
		const int			req_grade_exec;

	public:
		Form();
		~Form();
		Form(std::string name, int req_sign, int req_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getReqGradeSign() const;
		int			getReqGradeExec() const;
		void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif
