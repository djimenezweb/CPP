#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "DEEP COPY" << std::endl;
		Cat	cat1;
		Cat	cat2 = cat1;
		Cat cat3;
		cat3 = cat1;
		std::cout << "cat1 address: " << &cat1 << " | cat1's brain address: ";
		cat1.printBrainAddress();
		std::cout << "cat2 address: " << &cat2 << " | cat2's brain address: ";
		cat2.printBrainAddress();
		std::cout << "cat3 address: " << &cat3 << " | cat3's brain address: ";
		cat3.printBrainAddress();
	}
	std::cout << std::endl;
	{
		std::cout << "CONSTRUCTORS" << std::endl;
		size_t size = 4;
		Animal *arr[size];

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
	}

	return (0);
}
