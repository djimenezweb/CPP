#include "BitcoinExchange.hpp"

// Return true if date is later than today's
bool	BitcoinExchange::isFutureDate(std::string date)
{
	std::time_t now = std::time(0);
	std::tm *tm = std::localtime(&now);
	char today[20];
	strftime(today, sizeof(today), "%Y-%m-%d", tm);
	return (date > today);
}

// Save parsed values into time structure
// and check if date has been parsed correctly
bool	validateDate(int &year, int &month, int &day)
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
bool	BitcoinExchange::parseDate(std::string &line, char delimiter)
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
/* 		if (bc_value < 0)
			return (false); */
		return (validateDate(year, month, day));
	}
	return (false);
}
