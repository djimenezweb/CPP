#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "CONSTRUCTORS" << std::endl;
	size_t size = 2;
	Animal *arr[size];

	//Animal animal;

	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}

	std::cout << std::endl << "MAKE SOUND" << std::endl;

	for (size_t i = 0; i < size; i++)
	{
		arr[i]->makeSound();
	}

	std::cout << std::endl << "DESTRUCTORS" << std::endl;

	for (size_t i = 0; i < size; i++)
	{
		delete arr[i];
	}
	
	return (0);
}
