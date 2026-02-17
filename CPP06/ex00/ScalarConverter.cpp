#include "ScalarConverter.hpp"
#include "converter.hpp"

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

State transition[__STATE_SIZE][__INPUT_SIZE] =
{
	//I_SIGN	I_DOT		I_DIGIT		I_SUFFIX	I_CHAR 
	{S_STRING,	S_STRING,	S_STRING,	S_STRING,	S_STRING},	// S_CHAR		Valid final states
	{S_STRING,	S_DOT,		S_INTEGER,	S_STRING,	S_STRING},	// S_INTEGER
	{S_STRING,	S_STRING,	S_FRACTION,	S_SUFFIX,	S_STRING},	// S_FRACTION
	{S_STRING,	S_STRING,	S_STRING,	S_STRING,	S_STRING},	// S_SUFFIX
	{S_STRING,	S_STRING,	S_STRING,	S_STRING,	S_STRING},	// S_STRING		Invalid final states
	{S_SIGN,	S_DOT,		S_INTEGER,	S_CHAR,		S_CHAR	},	// S_START
	{S_STRING,	S_STRING,	S_INTEGER,	S_STRING,	S_STRING},	// S_SIGN
	{S_STRING,	S_STRING,	S_FRACTION,	S_STRING,	S_STRING},	// S_DOT
};

Input get_input_type(char c)
{
	if (c == '+' || c == '-')
		return (I_SIGN);
	else if (c == '.')
		return (I_DOT);
	else if (std::isdigit(c))
		return (I_DIGIT);
	else if (c == 'f')
		return (I_SUFFIX);
	return (I_CHAR);
}

State detect(const std::string &str)
{
	State state = S_START;
	size_t i = 0;

	while (i < str.length())
	{
		Input input = get_input_type(str[i]);
		state = transition[state][input];
		if (state == S_STRING)
			return (S_STRING);
		i++;
	}
	if (state >= S_STRING)
		return (S_STRING);
	return (state);
}

// Convert
void ScalarConverter::convert(const std::string &str)
{
	void (*actions[])(const std::string&) =
		{ str_to_char, str_to_int, str_to_double, str_to_float, print_string };

	State state = detect(str);
	actions[state](str);
}
