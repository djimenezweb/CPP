#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

// Copy assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter() {}

Input get_input_type(char c)
{
	if (std::isdigit(c))
		return (I_DIGIT);
	else if (c == 'f')
		return (I_SUFFIX);
	else if (std::isalpha(c))
		return (I_CHAR);
	else if (c == '.')
		return (I_DOT);
	else if (c == '+' || c == '-')
		return (I_SIGN);
	return (I_OTHER);
}

std::string type_str[__TYPE_SIZE] =
{
	"char",
	"string",
	"int",
	"double",
	"float",
	"invalid"
};

State transition[__STATE_SIZE][__INPUT_SIZE] =
{
	// I_DIGIT		I_CHAR		I_DOT		I_SIGN		I_SUFFIX	I_OTHER
	{S_INVALID,		S_STRING,	S_INVALID,	S_INVALID,	S_STRING,	S_INVALID},	// S_CHAR		Valid final states
	{S_INVALID,		S_STRING,	S_INVALID,	S_INVALID,	S_STRING,	S_INVALID}, // S_STRING
	{S_INTEGER,		S_INVALID,	S_DOT,		S_INVALID,	S_INVALID,	S_INVALID},	// S_INTEGER
	{S_FRACTION,	S_INVALID,	S_INVALID,	S_INVALID,	S_SUFFIX,	S_INVALID},	// S_FRACTION
	{S_INVALID,		S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID},	// S_SUFFIX
	{S_INVALID,		S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID},	// S_INVALID	Invalid final states
	{S_INTEGER,		S_CHAR,		S_DOT,		S_SIGN,		S_CHAR,		S_INVALID},	// S_START
	{S_INTEGER,		S_STRING,	S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID},	// S_SIGN
	{S_FRACTION,	S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID,	S_INVALID},	// S_DOT
};

Type detect(std::string &str)
{
	State state = S_START;
	size_t i = 0;

	while (i < str.length())
	{
		Input input = get_input_type(str[i]);
		state = transition[state][input];
		i++;
	}
	if (state >= S_INVALID)
		return (T_INVALID);
	return ((Type)state);
}

// Convert
void ScalarConverter::convert(std::string str)
{
/* 	cout << "  char: " << str << endl
		 << "   int: " << str << endl
		 << " float: " << str << endl
		 << "double: " << str << endl; */
	Type type = detect(str);
	std::cout << str << " -> " << type_str[type] << std::endl;
}
