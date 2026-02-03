#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define IDEA_SIZE 100

class Brain
{
	private:
		std::string ideas[IDEA_SIZE];

	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
};

#endif
