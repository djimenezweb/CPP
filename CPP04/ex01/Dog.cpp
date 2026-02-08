#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "🐶 Dog created" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "🐶 Dog copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	std::cout << "🐶 Dog copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog()
{
	delete brain;
	std::cout << "🐶 Dog destroyed" << std::endl;
}

// Make sound
void Dog::makeSound() const
{
	std::cout << "🐶 Woof! Woof!" << std::endl;
}
