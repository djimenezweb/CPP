#include <iostream>

int main()
{
	std::string	var = "HI THIS IS BRAIN";
	std::string	*ptr = &var;
	std::string	&ref = var;

	std::cout	<< "var address: " << &var << std::endl
				<< "ptr address: " << ptr << std::endl
				<< "ref address: " << &ref << std::endl
				<< std::endl
				<< "var value: " << var << std::endl
				<< "ptr value: " << *ptr << std::endl
				<< "ref value: " << ref << std::endl;

	return (0);
}