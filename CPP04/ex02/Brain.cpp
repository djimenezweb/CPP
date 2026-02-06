#include "Brain.hpp"

// Default constructor
Brain::Brain()
{
	std::cout << "🧠 Brain created" << std::endl;
	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		ideas[i] = "Idea";
	}
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << "🧠 Brain copied via Copy constructor" << std::endl;
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		ideas[i] = other.ideas[i];
}

// Copy assignment operator overload `=`
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "🧠 Brain copied via Copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < IDEAS_SIZE; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "🧠 Brain destroyed" << std::endl;
}
