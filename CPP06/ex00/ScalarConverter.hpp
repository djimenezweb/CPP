#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>

enum Type {
	T_CHAR,
	T_STRING,
	T_INT,
	T_DOUBLE,
	T_FLOAT,
	T_INVALID,
	__TYPE_SIZE
};

enum State {
	S_CHAR,		// Valid final states
	S_STRING,
	S_INTEGER,
	S_FRACTION,
	S_SUFFIX,
	S_INVALID,	// Invalid final states
	S_START,
	S_SIGN,
	S_DOT,
	__STATE_SIZE
};

enum Input {
	I_DIGIT,
	I_CHAR,
	I_DOT,
	I_SIGN,
	I_SUFFIX,
	I_OTHER,
	__INPUT_SIZE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		static size_t detect_switch(std::string &str);

	public:
		static void convert(std::string str);
};

#endif
