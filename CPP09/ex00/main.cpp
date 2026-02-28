#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>

#define DB_FILE		"data-mini.csv"
#define DB_HEADER	"date,exchange_rate"

// https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c
bool parseDate(std::string line, std::map<std::string, float> &db)
{
	int		year, month, day;
	char	delim1, delim2, delim3;
	float	bt_value;

	// If line contains space return false
	// Invalidate future dates
	// Accept negative bitcoin values? unsigned float / float ?

	std::stringstream ss(line);
	if (ss >> year >> delim1 >> month >> delim2 >> day >> delim3 >> bt_value)
	{
		if (delim1 != '-' || delim2 != '-' || delim3 != ',')
			return (false);
	}

	std::tm tm = {};
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	std::time_t time = std::mktime(&tm);
	(void)time;

	if (tm.tm_year == year - 1900 && tm.tm_mon == month - 1 && tm.tm_mday == day)
	{
		std::pair<std::map<std::string,float>::iterator,bool> return_value;
		return_value = db.insert(std::pair<std::string,float>(line.substr(0, 10), bt_value));
		if (!return_value.second)
			std::cerr << "Duplicated date" << std::endl;
		return (return_value.second);
	}
	return	(false);
}

int main()
{
	std::ifstream db_file;
	std::map<std::string, float> db;

	db_file.open(DB_FILE);
	if (db_file.fail())
	{
		std::cerr << "Failed to open database" << std::endl;
		return (1);
	}

	// What can we do with empty lines (containing \n only)???
	std::string	line;
	while (!db_file.eof())
	{
		getline(db_file, line);
		if (line == DB_HEADER)
			continue;
		if (!parseDate(line, db))
		{
			std::cerr << "Failed to parse line '" << line << "'" << std::endl;
			return (1);
		}
	}

	return (0);
}
