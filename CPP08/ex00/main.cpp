#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int	main()
{
	{
		std::list<int> numbers;

		numbers.push_front(12);
		numbers.push_back(8521);
		numbers.push_front(7509);
		numbers.push_back(333);
		numbers.push_back(-52);
		numbers.push_back(7415);
		numbers.push_front(20826);
		numbers.push_back(-985);
		numbers.push_back(35724);

		try
		{
			easyfind(numbers, 333);
			easyfind(numbers, 35724);
			easyfind(numbers, -985);
			easyfind(numbers, 111);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error (list): " << e.what() << '\n';
		}

		const std::list<int> const_numbers = numbers;

		try
		{
			easyfind(const_numbers, 333);
			easyfind(const_numbers, 35724);
			easyfind(const_numbers, -985);
			easyfind(const_numbers, 111);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error (const list): " << e.what() << '\n';
		}
	}

	{
		std::vector<int> numbers;

		numbers.push_back(12);
		numbers.push_back(8521);
		numbers.push_back(7509);
		numbers.push_back(333);
		numbers.push_back(-52);
		numbers.push_back(7415);
		numbers.push_back(20826);
		numbers.push_back(-985);
		numbers.push_back(35724);

		try
		{
			easyfind(numbers, 333);
			easyfind(numbers, 35724);
			easyfind(numbers, -985);
			easyfind(numbers, 111);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error (vector): " << e.what() << '\n';
		}
	}

	{
		std::deque<int> numbers;

		numbers.push_back(12);
		numbers.push_front(8521);
		numbers.push_back(7509);
		numbers.push_back(333);
		numbers.push_back(-52);
		numbers.push_back(7415);
		numbers.push_back(20826);
		numbers.push_front(-985);
		numbers.push_back(35724);

		try
		{
			easyfind(numbers, 333);
			easyfind(numbers, 35724);
			easyfind(numbers, -985);
			easyfind(numbers, 111);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error (deque): " << e.what() << '\n';
		}
	}

	return 0;
}
