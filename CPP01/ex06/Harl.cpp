#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ " DEBUG " ]" << std::endl
			  << DEBUG_MSG << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ " INFO " ]" << std::endl
			  << INFO_MSG << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ " WARNING " ]" << std::endl
			  << WARNING_MSG << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ " ERROR " ]" << std::endl
			  << ERROR_MSG << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	int	index;

	std::string levels[4] = { DEBUG, INFO, WARNING, ERROR };

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break ;
		}
		index = -1;
	}

	switch (index)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << DEFAULT_MSG << std::endl;
			break;
	}
}
