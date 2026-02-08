#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << "CONSTRUCTORS" << std::endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << std::endl << "TYPE" << std::endl;
		std::cout << "meta is of type: " << meta->getType() << " " << std::endl;
		std::cout << "i is of type: " << i->getType() << " " << std::endl;
		std::cout << "j is of type: " << j->getType() << " " << std::endl;

		std::cout << std::endl << "MAKE SOUND" << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl << "DESTRUCTORS" << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "WRONG ANIMAL CONSTRUCTORS" << std::endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();

		std::cout << std::endl << "TYPE" << std::endl;
		std::cout << "i is of type: " << i->getType() << " " << std::endl;
		
		std::cout << std::endl << "MAKE SOUND" << std::endl;
		i->makeSound();
		meta->makeSound();

		std::cout << std::endl << "DESTRUCTORS" << std::endl;
		delete meta;
		delete i;
	}

	return (0);
}
