#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange()
{
	openDb();
}

// Parameterized constructor
BitcoinExchange::BitcoinExchange(char *str) : input_filename(str)
{
	openDb();
	input_file.open(str);
	if (input_file.fail())
		throw std::runtime_error(std::string("Failed to open input file: '") + str + "'");
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	input_filename(other.input_filename),
	db(other.db)
{
	input_file.open(other.input_filename.c_str());
	if (input_file.fail())
		throw std::runtime_error(std::string("Failed to open input file: '") + input_filename + "'");
}

// Copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		input_filename = other.input_filename;
		db = other.db;
		input_file.open(other.input_filename.c_str());
		if (input_file.fail())
			throw std::runtime_error(std::string("Failed to open input file: '") + input_filename + "'");
	}
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	if (db_file.is_open())
		db_file.close();
	if (input_file.is_open())
		input_file.close();
}
