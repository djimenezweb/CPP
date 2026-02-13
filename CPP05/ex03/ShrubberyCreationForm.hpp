#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Tree.hpp"

# define SHRUB_SIGN 145
# define SHRUB_EXEC 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void	executeAction() const;
};

#endif
