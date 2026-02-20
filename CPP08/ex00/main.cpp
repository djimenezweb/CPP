#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int	main()
{

	std::list<int> numbers;
	// std::vector<int> numbers;
	// std::deque<int> numbers;

	numbers.push_back(12);
	numbers.push_back(8521);
	numbers.push_back(7509);
	numbers.push_back(333);
	numbers.push_back(-52);
	numbers.push_back(7415);
	numbers.push_back(20826);
	numbers.push_back(-985);
	numbers.push_back(35724);

	const std::list<int> c_numbers = numbers;

	try
	{
		easyfind(c_numbers, 35724);
		easyfind(numbers, 333);
		easyfind(numbers, 35724);
		easyfind(numbers, -985);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}
