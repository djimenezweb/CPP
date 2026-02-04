#include "Brain.hpp"

// Default constructor
Brain::Brain() {}

// Copy constructor
Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < IDEA_SIZE; i++)
		ideas[i] = other.ideas[i];
}

// Copy assignment operator overload `=`
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < IDEA_SIZE; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "🧠 Brain destroyed" << std::endl;
}
