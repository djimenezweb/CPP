#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "🙀 WrongCat created" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "🙀 WrongCat copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🙀 WrongCat copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "🙀 WrongCat destroyed" << std::endl;
}

// Make sound
void WrongCat::makeSound() const
{
	std::cout << "🙀 Meow!" << std::endl;
}
