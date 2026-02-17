#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <exception>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	randomizer(int min, int max)
{
	// int random_number = (std::rand() % max) + min + 1;
	int random_number = (std::rand() % (max - min + 1)) + min;
	return (random_number);
}

// Randomly instantiate `A`, `B`, or `C` and return the instance as a `Base` pointer
Base * generate(void)
{
	Base *ptr;

	int random_number = randomizer(0, 2);

	if (random_number == 2)
	{
		ptr = new A();
		std::cout << "Instantiated object of type A" << std::endl;
	}
	else if (random_number == 1)
	{
		ptr = new B();
		std::cout << "Instantiated object of type B" << std::endl;
	}
	else
	{
		ptr = new C();
		std::cout << "Instantiated object of type C" << std::endl;
	}

	return (ptr);
}


// Print the actual type of the object pointed to by `p`: "A", "B", or "C".
void identify(Base* p)
{
	A* a_ptr = dynamic_cast<A*>(p);
	B* b_ptr = dynamic_cast<B*>(p);
	C* c_ptr = dynamic_cast<C*>(p);

	if (a_ptr != NULL)
		std::cout << "Object is of class A" << std::endl;
	else if (b_ptr != NULL)
		std::cout << "Object is of class B" << std::endl;
	else if (c_ptr != NULL)
		std::cout << "Object is of class C" << std::endl;
	else
		std::cout << "Object is of unknown class" << std::endl;
}

/* Print the actual type of the object referenced by `p`: "A", "B", or "C".
Using a pointer inside this function is forbidden. */
void identify(Base& p)
{
	try
	{
		A& a_ref = dynamic_cast<A&>(p);
		(void)a_ref;
		std::cout << "Reference is of class A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			B& b_ref = dynamic_cast<B&>(p);
			(void)b_ref;
			std::cout << "Reference is of class B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				C& c_ref = dynamic_cast<C&>(p);
				(void)c_ref;
				std::cout << "Reference is of class C" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "Reference is of unknown class" << std::endl;
			}
			
		}
	}
}

int	main()
{
	std::srand((unsigned int)std::time(0) ^ (unsigned int)getpid());

	Base *obj = generate();
	Base &ref = *obj;

	identify(obj);
	identify(ref);

	delete obj;

	return (0);
}
