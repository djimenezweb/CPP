#include "ScalarConverter.hpp"

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

// Return type of the passed literal string
size_t ScalarConverter::detect_switch(string &str)
{
	State state = S_START;
	size_t i = 0;
	while (i < str.length())
	{
		char c = str[i];
		switch (state)
		{
			case S_START:
				if (c == '-' || c == '+')
					state = S_SIGN;
				else if (std::isalpha(c))
					state = S_CHAR;
				else if (std::isdigit(c))
					state = S_INTEGER;
				else
					state = S_INVALID;
				break;

			case S_CHAR:
					state = S_INVALID;
				break;

			case S_SIGN:
				if (std::isdigit(c))
					state = S_INTEGER;
				else
					state = S_INVALID;
				break;

			case S_INTEGER:
				if (std::isdigit(c))
					state = S_INTEGER;
				else if (c == '.')
					state = S_DOT;
				else
					state = S_INVALID;
				break;

			case S_DOT:
				if (std::isdigit(c))
					state = S_FRACTION;
				else
					state = S_INVALID;
				break;

			case S_FRACTION:
				if (std::isdigit(c))
					state = S_FRACTION;
				else if (c == 'f')
					state = S_SUFFIX;
				else
					state = S_INVALID;
				break;

			case S_SUFFIX:
				if (c == '\0')
					state = S_SUFFIX;
				else
					state = S_INVALID;
				break;
			
			case S_INVALID:
				return (S_INVALID);
		}
		i++;
	}
	return (state);
}
