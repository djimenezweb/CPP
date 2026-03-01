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
		std::map<std::string, float>	db;

		void	openDb();
		bool	parseDate(std::string &line, char delimiter);
		bool	insert(std::string &line);

	public:
		BitcoinExchange();
		BitcoinExchange(char *str);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	printDb();
		void	getExchangeRate();
};

#endif
