#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			req_grade_sign;
		const int			req_grade_exec;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int req_sign, int req_exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getReqGradeSign() const;
		int				getReqGradeExec() const;
		void			beSigned(Bureaucrat const &bureaucrat);
		void			execute(Bureaucrat const &bureaucrat) const;
		virtual void	executeAction() const = 0;

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

		class NotSignedException : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const AForm &other);

#endif
