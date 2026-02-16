#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include "data.hpp"

// struct Data;
// You must create a non-empty (meaning it has data members) Data structure

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
