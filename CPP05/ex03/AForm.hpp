#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

/* ESTA CLASE TODAVÍA NO ES ABSTRACTA, hay que asignar algún método virtual a 0... ¿CUÁL? */

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

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getReqGradeSign() const;
		int			getReqGradeExec() const;
		void		beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

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
std::ostream &operator<<(std::ostream &output, const AForm *other);

#endif
