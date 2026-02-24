#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(10000);

	try
	{
		sp.fill();
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(17);
		// sp.addNumber(18);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
