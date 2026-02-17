#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error. Correct usage: " << argv[0] << " <arg>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	/* std::cout << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("123");
	ScalarConverter::convert(" ");
	ScalarConverter::convert("00123");
	ScalarConverter::convert("-33");
	ScalarConverter::convert("+33");
	ScalarConverter::convert("-129");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-127");
	ScalarConverter::convert("126");
	ScalarConverter::convert("127");
	ScalarConverter::convert("n");
	ScalarConverter::convert("c");
	ScalarConverter::convert("f");
	ScalarConverter::convert("*");
	ScalarConverter::convert("42");
	ScalarConverter::convert("42.0");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert(".5f");
	ScalarConverter::convert("11.666");
	ScalarConverter::convert(".5");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-4.2");
	ScalarConverter::convert("4.2");
	
	std::cout << std::endl << "Pseudo-literals: " << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");

	std::cout << std::endl << "Overflows: " << std::endl;
	ScalarConverter::convert("-129");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-129.0");
	ScalarConverter::convert("128.0");
	ScalarConverter::convert("-129.0f");
	ScalarConverter::convert("128.0f");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483649.0");
	ScalarConverter::convert("2147483648.0");
	ScalarConverter::convert("-2147483649.0f");
	ScalarConverter::convert("2147483648.0f");

	std::cout << std::endl << "Invalid examples: " << std::endl;
	ScalarConverter::convert("hola");
	ScalarConverter::convert("n.an");
	ScalarConverter::convert("13.an");
	ScalarConverter::convert("(?)");
	ScalarConverter::convert("++33");
	ScalarConverter::convert("123.");
	ScalarConverter::convert("+");
	ScalarConverter::convert("42.0z");
	ScalarConverter::convert("     "); */
}
