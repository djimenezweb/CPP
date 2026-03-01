#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::string		expr;
		std::stack<int>	stack;
		void pushDigit(size_t idx);
		void operate(char c);

	public:
		RPN();
		RPN(std::string args);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		int calc();

		class UnexpectedTokenException : public std::exception
		{
			private :
				std::string message;
			public :
				UnexpectedTokenException(char c) throw();
				~UnexpectedTokenException() throw() {};
				const char *what() const throw();
		};
};

#endif
