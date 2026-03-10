#include "BitcoinExchange.hpp"

// Extract double value from a string starting at the specified position
double BitcoinExchange::extract_double_at(const std::string &str, size_t i) const
{
	std::stringstream ss(str.substr(i));
	double value;
	ss >> value;
	return (value);
}

// Return string formatted as "YYYY-MM-DD => input_value = exchange_rate"
std::string BitcoinExchange::printExchangeRate(const std::string &line) const
{
	if (!isspace(line[10]) || line.find('|') != 11 || !isspace(line[12]))
		return (std::string(ERROR "Invalid line: '") + line + "'");

	std::string date = line.substr(0,10);

	if (!parseDate(line, '|'))
		return (std::string(ERROR "Invalid date: '") + date + "'");
	
	if (isFutureDate(date))
		return (std::string(ERROR "Date '") + date + "' is in the future");

	double	bc_value = extract_double_at(line, 13);
	if (bc_value < MIN_VALUE)
		return (std::string(ERROR "Invalid negative value: ") + line.substr(13));
	if (bc_value > MAX_VALUE)
		return (std::string(ERROR "Too large value: ") + line.substr(13));

	if (date < db.begin()->first)
		return (std::string(ERROR "Date '") + date + "' is out of range");

	std::map<std::string, double>::const_iterator found = db.upper_bound(date);
	if (found != db.begin())
		found--;

	std::stringstream result;
	result << std::fixed << bc_value * found->second;
	return (std::string(date + " => " + line.substr(13) + " = " + result.str()));
}

// Read input file line by line and print exchange rate
void BitcoinExchange::getExchangeRate()
{
	std::string	line;

	getline(input_file, line);
	if (line != INPUT_HEADER)
		throw std::runtime_error(ERROR "Wrong or missing header in input file");
	while (!input_file.eof())
	{
		getline(input_file, line);
		if (line.empty())
			continue;
		std::cout << printExchangeRate(line) << std::endl;}
}
