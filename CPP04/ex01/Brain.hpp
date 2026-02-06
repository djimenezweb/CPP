#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define IDEAS_SIZE 100

class Brain
{
	private:
	
	public:
		std::string ideas[IDEAS_SIZE];
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
};

#endif
