#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog")
{
	std::cout << "🐶 Dog created" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "🐶 Dog copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🐶 Dog copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "🐶 Dog destroyed" << std::endl;
}

// Make sound
void Dog::makeSound() const
{
	std::cout << "🐶 Woof! Woof!" << std::endl;
}
