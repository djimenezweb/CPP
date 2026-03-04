#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <ctime>
# include <limits>
# include <exception>
 
#define DB_FILE			"data.csv"
#define DB_HEADER		"date,exchange_rate"
#define INPUT_HEADER	"date | value"

class BitcoinExchange
{
	private:
		std::ifstream					db_file;
		std::ifstream					input_file;
		std::string						input_filename;
		std::map<std::string, float>	db;

		BitcoinExchange();

		void		openDb();
		bool		insert(std::string &line);

		bool		isFutureDate(std::string date);
		bool		parseDate(std::string &line, char delimiter);

		std::string	printExchangeRate(std::string &line);
		float		extract_float_at(std::string &str, size_t i);

	public:
		BitcoinExchange(char *str);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	printDb();
		void	getExchangeRate();
};

#endif
