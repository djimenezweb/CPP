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

// Return true if date is later than today's
bool isFutureDate(std::string date)
{
	std::time_t now = std::time(0);
	std::tm *tm = std::localtime(&now);
	char today[20];
	strftime(today, sizeof(today), "%Y-%m-%d", tm);
	return (date > today);
}

// Save parsed values into time structure
// and check if date has been parsed correctly
bool validateDate(int &year, int &month, int &day)
{
	if (year < 1000)
		return (false);
	std::tm tm = {};
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	std::time_t time = std::mktime(&tm);
	(void)time;
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

// Extract float value from a string starting at the specified position
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

// Open CSV database, read line by line and insert values in map
void BitcoinExchange::openDb()
{
	std::string	line;

	db_file.open(DB_FILE);
	if (db_file.fail())
		throw std::runtime_error("Error: Failed to open database");

	getline(db_file, line);
	if (line != DB_HEADER)
		throw std::runtime_error("Error: Wrong or missing header in database file");
	while (!db_file.eof())
	{
		getline(db_file, line);
		if (line.empty())
			break;
		if (line.find(',') != 10 || !parseDate(line, ','))
			throw std::runtime_error(std::string("Error: Failed to parse line '") + line + "'");
		if (!insert(line))
			throw std::runtime_error(std::string("Error: Failed to insert line '") + line + "' into database");
	}
	if (db.empty())
		throw std::runtime_error("Error: Database is empty");
}

// Read input file line by line and print exchange rate
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
		if (line.find('|') != 11 || !parseDate(line, '|'))
			throw std::runtime_error(std::string("Error: Failed to parse line '") + line + "'");
		
		std::string date = line.substr(0,10);
		if (isFutureDate(date))
			throw std::runtime_error(std::string("Error: Date '") + date + "' is in the future");

		float	bc_value = extract_float_at(line, 13);
		if (bc_value >= static_cast<float>(std::numeric_limits<int>::max()))
			throw std::runtime_error("Error: Too large value");

		if (date < db.begin()->first)
			throw std::runtime_error("Error: Date is out of range");

		std::map<std::string, float>::iterator found = db.upper_bound(date);
		if (found != db.begin())
			found--;
		std::cout << date << " => " << bc_value << " = " << (bc_value) * (found->second) << std::endl; 
	}
}

// Print database contents
void	BitcoinExchange::printDb()
{
	if (db.empty())
		throw std::runtime_error("Error: Database is empty");

	std::map<std::string, float>::iterator it = db.begin();
	std::map<std::string, float>::iterator it_end = db.end();

	while (it != it_end)
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}
