#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR "Correct usage: " << argv[0] << " <file> " << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange	bce(argv[1]);
		bce.getExchangeRate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}
