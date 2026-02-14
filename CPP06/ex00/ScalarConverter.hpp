#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>

using std::cout;
using std::cerr;
using std::string;
using std::endl;

class ScalarConverter
{
	private:
		enum type {
			T_CHAR,
			T_INT,
			T_FLOAT,
			T_DOUBLE
		};

		enum state {
			S_START,
			S_CHAR,
			S_SIGN,
			S_INTEGER,
			S_DOT,
			S_FRACTION,
			S_SUFFIX,
			S_INVALID
		};
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		static size_t detect(string &str);

	public:
		static void convert(string str);
};

#endif
