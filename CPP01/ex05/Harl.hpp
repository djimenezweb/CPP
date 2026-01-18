#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG "DEBUG"
# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "INFO"
# define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define WARNING "WARNING"
# define WARNING_MSG "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
# define ERROR "ERROR"
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
//typedef void(Harl::*f_ptr)();

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	void	complain(std::string level);
};

#endif