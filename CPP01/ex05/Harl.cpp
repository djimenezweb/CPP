#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string level)
{

	std::string levels[4] = { DEBUG, INFO, WARNING, ERROR };
	Harl::f_ptr functions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			break ;
		}
	}
}
