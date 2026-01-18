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
	//typedef void(Harl::*f_ptr)();
	std::string levels[4] = { DEBUG, INFO, WARNING, ERROR };
	void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	//void (Harl::*Harl::functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	//Harl::f_ptr functions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			break ;
		}
	}
}

// Thank you!!!
// https://stackoverflow.com/questions/10901959/function-pointers-in-c-error-must-use-or-to-call-pointer-to-memb
// https://stackoverflow.com/questions/759512/internal-typedefs-in-c-good-style-or-bad-style
