#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>
#include <limits>

#define DB_FILE			"data.csv"
#define DB_HEADER		"date,exchange_rate"
#define INPUT_HEADER	"date | value"

float extract_float_at(std::string &str, size_t i)
{
	std::stringstream ss(str.substr(i));
	float value;
	ss >> value;
	return (value);
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

// Insert date & value into database
bool insert(std::string &line, std::map<std::string, float> &db)
{
	float	bc_value = extract_float_at(line, 11);
	if (bc_value > static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cerr << "Error: Too large value" << std::endl;
		return (false);
	}
	std::pair<std::map<std::string,float>::iterator,bool> return_value;

	return_value = db.insert(std::pair<std::string,float>(line.substr(0, 10), bc_value));
	if (!return_value.second)
		std::cerr << "Duplicated date" << std::endl;
	return (return_value.second);
}

// Load line into stream and extract values
bool parseDate(std::string &line, char delimiter)
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

void close_files(std::ifstream &file1, std::ifstream &file2)
{
	if (file1.is_open())
		file1.close();
	if (file2.is_open())
		file2.close();
}

void exchange_rate(std::string &line, std::map<std::string, float> &db)
{
	std::string date = line.substr(0,10);
	
	float	bc_value = extract_float_at(line, 13);
	if (bc_value >= static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cerr << "Error: Too large value" << std::endl;
		return;
	}

	if (date < db.begin()->first)
	{
		std::cerr << "Error: Date is out of range" << std::endl;
		return;
	}
	std::map<std::string, float>::iterator found = db.upper_bound(date);
	if (found != db.begin())
		found--;
	std::cout << date << " => " << bc_value << " = " << bc_value * found->second << std::endl; 
}

int main(int argc, char* argv[])
{
	std::ifstream db_file;
	std::ifstream input;
	std::map<std::string, float> db;

	if (argc != 2)
	{
		std::cerr << "Correct usage: " << argv[0] << " <file> " << std::endl;
		return (1);
	}

	db_file.open(DB_FILE);
	if (db_file.fail())
	{
		std::cerr << "Failed to open database: '" << DB_FILE << "'" << std::endl;
		return (1);
	}

	input.open(argv[1]);
	if (input.fail())
	{
		std::cerr << "Failed to open input file: '" << argv[1] << "'" << std::endl;
		close_files(db_file, input);
		return (1);
	}

	std::string	line;
	while (!db_file.eof())
	{
		getline(db_file, line);
		if (line.empty())
			break;
		if (line == DB_HEADER)
			continue;
		if (!parseDate(line, ','))
		{
			std::cerr << "Failed to parse line '" << line << "'" << std::endl;
			close_files(db_file, input);
			return (1);
		}
		if (!insert(line, db))
		{
			std::cerr << "Failed to insert line '" << line << "' into database" << std::endl;
			close_files(db_file, input);
			return (1);
		}
	}
	while (!input.eof())
	{
		getline(input, line);
		if (line.empty())
			break;
		if (line == INPUT_HEADER)
			continue;
		if (!parseDate(line, '|'))
		{
			std::cerr << "Failed to parse line '" << line << "'" << std::endl;
			close_files(db_file, input);
			return (1);
		}
		exchange_rate(line, db);
	}

	close_files(db_file, input);

	return (0);
}
