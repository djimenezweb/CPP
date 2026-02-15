#ifndef STATE_MACHINE_H
# define STATE_MACHINE_H

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
	I_SIGN,
	I_DOT,
	I_DIGIT,
	I_SUFFIX,
	I_CHAR,
	I_OTHER,
	__INPUT_SIZE
};

Input	get_input_type(char c);
Type	detect(const std::string &str);

#endif
