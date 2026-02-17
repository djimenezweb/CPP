#include "Serializer.hpp"

int	main()
{
	Data		data;
	Data		*data_ptr = NULL;
	uintptr_t	serialized;
	
	data.letter = 'a';
	data.number = 123;

	std::cout << "data.letter: " << data.letter << std::endl
			  << "data.number: " << data.number << std::endl;

	serialized = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(serialized);

	std::cout << std::endl
			  << &data << std::endl
			  << data_ptr << std::endl;

	std::cout << std::endl
			  << "data_ptr->letter: " << data_ptr->letter << std::endl
			  << "data_ptr->number: " << data_ptr->number << std::endl;

	return (0);
}
