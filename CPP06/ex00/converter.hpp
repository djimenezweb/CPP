#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <climits>
# include <cfloat>
# include <cmath>
# include <iomanip>

# include "ScalarConverter.hpp"

// Finite state machine

enum State {
	S_CHAR,		// Valid final states
	S_INTEGER,
	S_FRACTION,
	S_SUFFIX,
	S_STRING,	// Invalid final states
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
	__INPUT_SIZE
};

// Input	get_input_type(char c);
// State	detect(const std::string &str);

// Print

int		calc_precision(const std::string &str);
void	print_double(const double d, const std::string &str);
void	print_float(const float f, const std::string &str);
void	print_int(const int i, const std::string &str);
void	print_char(const char c, const std::string &str);
void	print_string(const std::string &str);

// Conversions

void	out_of_range(const std::string &str, std::string type);
void	convert_double(const std::string &str);
void	convert_float(const std::string &str);
void	convert_int(const std::string &str);
void	convert_char(const std::string &str);

// Limits

bool	is_quoted_char(const std::string &str);
bool	is_pseudo_lit(const std::string &str);
bool	is_valid_double(const std::string &str);
bool	is_valid_float(const std::string &str);
bool	is_valid_int(const std::string &str);
bool	is_valid_char(const std::string &str);

#endif
