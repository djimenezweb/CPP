#include "Serializer.hpp"

// Source: https://en.cppreference.com/w/cpp/language/reinterpret_cast.html

int	main()
{

	Data		data;
	Data		*data_ptr = NULL;
	uintptr_t	value;
	
	data.c = 'a';
	data.i = 123;

	value = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(value);

	std::cout << &data << std::endl;
	std::cout << data_ptr << std::endl;
	return (0);
}
