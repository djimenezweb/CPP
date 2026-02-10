#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other);

class GradeTooHighException : public std::exception
{
	public :
		const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
		{
			return ("Grade too high");
		};
};

class GradeTooLowException : public std::exception
{
	public :
		const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
		{
			return ("Grade too low");
		};
};

#endif
