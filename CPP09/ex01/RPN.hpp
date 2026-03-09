#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <exception>

# define ERROR	"\033[31;1mError: \033[0m"

class RPN
{
	private:
		std::string			expr;
		std::stack<double>	stack;
		void operate(char c);

	public:
		RPN();
		RPN(std::string args);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		double calc();

		class UnexpectedTokenException : public std::exception
		{
			private :
				std::string message;
			public :
				UnexpectedTokenException(char c) throw();
				virtual ~UnexpectedTokenException() throw() {};
				virtual const char *what() const throw();
		};
};

#endif
