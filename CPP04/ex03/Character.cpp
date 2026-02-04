#include "Character.hpp"

// Default constructor
Character::Character() {}

// Copy constructor
Character::Character(const Character &other) {}

// Copy assignment operator overload `=`
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
Character::~Character()
{
	// Delete allocated memory
}
