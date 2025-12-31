#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

std::string	trunc_str(std::string str, int max_size);
std::string trim(std::string& str);
bool	is_valid_phone(std::string str);

#endif