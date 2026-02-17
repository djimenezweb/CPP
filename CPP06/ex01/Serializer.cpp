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

// Take a pointer and convert it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	value;
	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

// Take an unsigned integer parameter and convert it to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr;
	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
