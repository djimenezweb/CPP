#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <ctime>
# include <limits>
# include <exception>
 
# define DB_FILE		"data.csv"
# define DB_HEADER		"date,exchange_rate"
# define INPUT_HEADER	"date | value"
# define ERROR			"\033[31;1mError: \033[0m"
# define MIN_VALUE		0
# define MAX_VALUE		1000

class BitcoinExchange
{
	private:
		std::ifstream					db_file;
		std::ifstream					input_file;
		const std::string				input_filename;
		std::map<std::string, float>	db;

		BitcoinExchange();

		void		openDb();
		bool		insert(const std::string &line);
		bool		isFutureDate(const std::string &date) const;
		bool		parseDate(const std::string &line, char delimiter) const;
		std::string	printExchangeRate(const std::string &line) const;
		float		extract_float_at(const std::string &str, size_t i) const;

	public:
		BitcoinExchange(const char *str);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	printDb() const;
		void	getExchangeRate();
};

#endif
