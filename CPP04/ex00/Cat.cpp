#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat")
{
	std::cout << "🐱 Cat created" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "🐱 Cat copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🐱 Cat copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "🐱 Cat destroyed" << std::endl;
}

// Make sound
void Cat::makeSound() const
{
	std::cout << "🐱 Meow!" << std::endl;
}
