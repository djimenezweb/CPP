#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Correct usage: " << argv[0] << " <expression>" << std::endl;
		return (1);
	}

	try
	{
		RPN calculator(argv[1]);
		std::cout << calculator.calc() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
