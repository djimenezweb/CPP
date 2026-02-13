#include <iostream>
#include <fstream>

void	file_err(std::string name)
{
	std::cout << "Error opening file: '" << name << "'" << std::endl;
}

std::string	replace(std::string line, std::string s1, std::string s2)
{
	std::string::size_type	i;

	if (s1.empty())
		return (line);
	i = line.find(s1);
	while (i != std::string::npos)
	{
		line = line.substr(0, i) + s2 + line.substr(i + s1.length());
		i = line.find(s1, i + s2.length());
	}
	return (line);
}

int	main(int argc, char *argv[])
{
	std::string		infile;
	std::string		outfile;
	std::ifstream	istream;
	std::ofstream	ostream;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Correct usage: ./replace <file> <str1> <str2>" << std::endl;
		return (1);
	}

	infile = argv[1];
	outfile = infile + ".replace";
	istream.open(argv[1]);
	if (istream.fail())
		return (file_err(infile), 1);
	ostream.open(outfile.c_str());
	if (ostream.fail())
		return (istream.close(), file_err(outfile), 1);

	while (!istream.eof())
	{
		getline(istream, line, '\0');
		ostream << replace(line, argv[2], argv[3]);
	}

	istream.close();
	ostream.close();
	return (0);
}
