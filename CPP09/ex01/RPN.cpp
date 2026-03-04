#include "RPN.hpp"

// Default constructor
RPN::RPN() : expr("")
{}

// Parameterized constructor
RPN::RPN(std::string args) : expr(args)
{}

// Copy constructor
RPN::RPN(const RPN &other)
{
	expr = other.expr;
	stack = other.stack;
}

// Copy assignment operator
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		expr = other.expr;
		stack = other.stack;
	}
	return (*this);
}

// Destructor
RPN::~RPN()
{}

void RPN::operate(char c)
{
	if (stack.size() < 2)
		throw (RPN::UnexpectedTokenException(c));

	double a, b;
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();

	switch (c)
	{
	case ('+'):
		stack.push(b + a);
		break;
	case ('-'):
		stack.push(b - a);
		break;
	case ('*'):
		stack.push(b * a);
		break;
	case ('/'):
	{
		if (a == 0)
			throw (std::runtime_error("Error: Can't divide between 0"));
		stack.push(b / a);
		break;
	}
	default:
		throw (RPN::UnexpectedTokenException(c));
		break;
	}
}

double RPN::calc()
{
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (isspace(expr[i]))
			continue;
		else if (i + 1 < expr.length() && !isspace(expr[i + 1]))
			throw (RPN::UnexpectedTokenException(expr[i + 1]));
		if (isdigit(expr[i]))
			stack.push(expr[i] - '0');
		else
			operate(expr[i]);
	}
	if (stack.size() != 1)
		throw (std::runtime_error("Error: Missing operator (+, -, *, /)"));
	return (stack.top());
}

RPN::UnexpectedTokenException::UnexpectedTokenException(char c) throw() :
	message(std::string("Error: Unexpected token '") + c + "'")
{}

const char* RPN::UnexpectedTokenException::what() const throw()
{
	return (message.c_str());
}
