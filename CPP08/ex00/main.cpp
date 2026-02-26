#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int	main()
{
	{
		std::cout << "== TEST 1 == List ==" << std::endl;
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
			std::cerr << "Error: " << e.what() << '\n';
		}

		std::cout << std::endl << "== TEST 2 == Const list ==" << std::endl;

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
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	{
		std::cout << std::endl << "== TEST 3 == Vector ==" << std::endl;

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
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	{
		std::cout << std::endl << "== TEST 4 == Deque ==" << std::endl;

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
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	return 0;
}
