#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "Correct usage: " << argv[0] << " <arguments...>" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe pme(argv);
		// std::cout << pme.sort() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
