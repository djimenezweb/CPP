#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("undefined")
{
	std::cout << "🐾 Undefined Animal created" << std::endl;
}

// Parameterized constructor
Animal::Animal(std::string set_type) : type(set_type)
{
	std::cout << "🐾 Animal of type " << set_type << " created" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "🐾 Animal copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🐾 Animal copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
Animal::~Animal()
{
	std::cout << "🐾 Animal destroyed" << std::endl;
}

// Getter
std::string Animal::getType() const
{
	return (type);
}

// Setter
void Animal::setType(std::string set_type)
{
	type = set_type;
}

// Make sound
void Animal::makeSound() const
{
	std::cout << "🤐 Undefined animals make no sound" << std::endl;
}
