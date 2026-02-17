#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <cassert>
# include <stdint.h>
# include <iostream>
# include <iomanip>

struct Data
{
	int		i;
	char	c;
};

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
