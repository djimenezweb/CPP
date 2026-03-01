#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange()
{
	db_file.open(DB_FILE);
	if (db_file.fail())
		throw std::runtime_error("Error: Failed to open database");
	openDb();
	if (db.empty())
		throw std::runtime_error("Error: Failed to load database");
}

// Parameterized constructor
BitcoinExchange::BitcoinExchange(char *str)
{
	db_file.open(DB_FILE);
	if (db_file.fail())
		throw std::runtime_error("Error: Failed to open database");
	openDb();
	if (db.empty())
		throw std::runtime_error("Error: Failed to load database");
	input_file.open(str);
	if (input_file.fail())
		throw std::runtime_error(std::string("Failed to open input file: '") + str + "'");
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	// TO DO!!
	(void)other;
}

// Copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		// TO DO!!
		// Copy values
	}
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "Destructor" << std::endl;
	if (db_file.is_open())
		db_file.close();
	if (input_file.is_open())
		input_file.close();
}

bool validateDate(int &year, int &month, int &day)
{
	// Invalidate future dates ???

	// Save parsed values into time structure
	std::tm tm = {};
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	std::time_t time = std::mktime(&tm);
	(void)time;

	// Check if date has been parsed correctly
	return (tm.tm_year == year - 1900 && tm.tm_mon == month - 1 && tm.tm_mday == day);
}

// Load line into stream and extract values
bool BitcoinExchange::parseDate(std::string &line, char delimiter)
{
	int		year, month, day;
	char	delim1, delim2, delim3;
	float	bc_value;

	std::stringstream ss(line);
	if (ss >> year >> delim1 >> month >> delim2 >> day >> delim3 >> bc_value)
	{
		ss >> std::ws;	// Remove trailing whitespace
		if (!ss.eof())
			return (false);
		if (delim1 != '-' || delim2 != '-' || delim3 != delimiter)
			return (false);
		if (bc_value < 0)
			return (false);
		return (validateDate(year, month, day));
	}
	return (false);
}

float extract_float_at(std::string &str, size_t i)
{
	std::stringstream ss(str.substr(i));
	float value;
	ss >> value;
	return (value);
}

// Insert date & value into database
bool BitcoinExchange::insert(std::string &line)
{
	float	bc_value = extract_float_at(line, 11);
	if (bc_value > static_cast<float>(std::numeric_limits<int>::max()))
		throw std::runtime_error("Error: Too large value");

	std::pair<std::map<std::string,float>::iterator,bool> return_value;
	return_value = db.insert(std::pair<std::string,float>(line.substr(0, 10), bc_value));
	if (!return_value.second)
		throw std::runtime_error("Error: Duplicated date");
	return (return_value.second);
}

// Open database
void BitcoinExchange::openDb()
{
	std::string	line;

	getline(db_file, line);
	if (line != DB_HEADER)
		throw std::runtime_error("Error: Wrong or missing header in database file");
	while (!db_file.eof())
	{
		getline(db_file, line);
		if (line.empty())
			break;
		if (!parseDate(line, ','))
			throw std::runtime_error(std::string("Error: Failed to parse line '") + line + "'");
		if (!insert(line))
			throw std::runtime_error(std::string("Error: Failed to insert line '") + line + "' into database");
	}
}

void BitcoinExchange::getExchangeRate()
{
	std::string	line;

	getline(input_file, line);
	if (line != INPUT_HEADER)
		throw std::runtime_error("Error: Wrong or missing header in input file");
	while (!input_file.eof())
	{
		getline(input_file, line);
		if (line.empty())
			break;
		if (!parseDate(line, '|'))
			throw std::runtime_error(std::string("Error: Failed to parse line '") + line + "'");
		
		std::string date = line.substr(0,10);
	
		float	bc_value = extract_float_at(line, 13);
		if (bc_value >= static_cast<float>(std::numeric_limits<int>::max()))
			throw std::runtime_error("Error: Too large value");

		std::cout << "db.begin()->first: " << db.begin()->first << std::endl;
		if (date < db.begin()->first)
			throw std::runtime_error("Error: Date is out of range");

		std::map<std::string, float>::iterator found = db.upper_bound(date);
		if (found != db.begin())
			found--;
		std::cout << date << " => " << bc_value << " = " << (bc_value) * (found->second) << std::endl; 
	}
}

void	BitcoinExchange::printDb()
{
	if (db.empty())
		throw std::runtime_error("Error: Database is empty");

	std::map<std::string, float>::iterator it = db.begin();
	std::map<std::string, float>::iterator it_end = db.end();

	while (it != it_end)
	{
		std::cout << "it->first: >" << it->first << "<";
		std::cout << " ";
		std::cout << "it->second: >" << it->second << "<";
		std::cout << std::endl;
		it++;
	}
}
