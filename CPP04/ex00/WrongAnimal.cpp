#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type("undefined")
{
	std::cout << "Undefined WrongAnimal created" << std::endl;
}

// Parameterized constructor
WrongAnimal::WrongAnimal(std::string set_type) : type(set_type)
{
	std::cout << "WrongAnimal of type " << set_type << " created" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "WrongAnimal copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Getter
std::string WrongAnimal::getType() const
{
	return (type);
}

// Setter
void WrongAnimal::setType(std::string set_type)
{
	type = set_type;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

// Make sound
void WrongAnimal::makeSound() const
{
	std::cout << "🤐 Undefined wrong animals make no sound" << std::endl;
}
