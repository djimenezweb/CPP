#include <iostream>
#include <fstream>

void	file_err(std::string name)
{
	std::cout << "Error opening file: '" << name << "'" << std::endl;
}

std::string	replace(std::string line, std::string s1, std::string s2)
{
	int			i;
	std::string	str;

	str = line;
	i = line.find(s1);
	while (!s1.empty() && i >= 0)
	{
		str = str.substr(0, i) + s2 + str.substr(i + s1.length());
		i = str.find(s1);
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	std::string		infile;
	std::string		outfile;
	std::ifstream	istream;
	std::ofstream	ostream;
	std::string		line;

	if (argc != 4)
		return (1);

	infile = argv[1];
	outfile = infile + ".replace";
	istream.open(argv[1]);
	if (istream.fail())
		return (file_err(infile), 1);
	ostream.open(outfile.c_str());
	if (ostream.fail())
		return (file_err(outfile), 1);

	while (!istream.eof())
	{
		getline(istream, line);
		ostream << replace(line, argv[2], argv[3]) << std::endl;
	}

	istream.close();
	ostream.close();
	return (0);
}
