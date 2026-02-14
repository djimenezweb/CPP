#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>

using std::cout;
using std::cerr;
using std::string;
using std::endl;

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		static void convert(string str);
};

#endif
