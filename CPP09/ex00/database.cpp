#include "BitcoinExchange.hpp"

// Insert date & value into database
bool	BitcoinExchange::insert(std::string &line)
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
void	BitcoinExchange::openDb()
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
