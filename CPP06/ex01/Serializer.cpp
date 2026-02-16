#include "Serializer.hpp"

// Default constructor
Serializer::Serializer() {}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

// Copy assignment operator overload
Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

// Destructor
Serializer::~Serializer() {}

// Takes a pointer and convert it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{

}

// Take an unsigned integer parameter and convert it to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw)
{

}
