#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		static void convert(const std::string &str);
};

#endif
