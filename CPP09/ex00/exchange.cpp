#include "BitcoinExchange.hpp"

// Extract float value from a string starting at the specified position
float BitcoinExchange::extract_float_at(std::string &str, size_t i)
{
	std::stringstream ss(str.substr(i));
	float value;
	ss >> value;
	return (value);
}

std::string BitcoinExchange::printExchangeRate(std::string &line)
{
	if (!isspace(line[10]) || line.find('|') != 11 || !isspace(line[12]))
		return (std::string("Error: Invalid line: '") + line + "'");

	std::string date = line.substr(0,10);

	if (!parseDate(line, '|'))
		return (std::string("Error: Invalid date: '") + date + "'");
	
	if (isFutureDate(date))
		return (std::string("Error: Date '") + date + "' is in the future");

	float	bc_value = extract_float_at(line, 13);
	if (bc_value < 0)
		return (std::string("Error: Invalid negative value: ") + line.substr(13));
	if (bc_value >= static_cast<float>(std::numeric_limits<int>::max()))
		return (std::string("Error: Too large value: ") + line.substr(13));

	if (date < db.begin()->first)
		return (std::string("Error: Date '") + date + "' is out of range");

	std::map<std::string, float>::iterator found = db.upper_bound(date);
	if (found != db.begin())
		found--;

	std::stringstream result;
	result << bc_value * found->second;
	return (std::string(date + " => " + line.substr(13) + " = " + result.str()));
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
		std::cout << printExchangeRate(line) << std::endl;}
}
