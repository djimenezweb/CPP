#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {}

// Parameterized constructor
PmergeMe::PmergeMe(int argc, char **argv) : argc(argc), argv(argv)
{}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
	// TO DO: Copy values
	(void)other;
}

// Copy assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// TO DO: Copy values
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {}

void PmergeMe::initVector()
{
	int			number;
	std::string	str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		std::stringstream ss(str);
		while (!ss.eof())
		{
			ss >> number;
			if (ss.fail())
				return;
			v.push_back(number);
		}
	}
}

bool PmergeMe::isSorted()
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
			return (false);
	}
	return (true);
}

void PmergeMe::printVector(std::vector<int> &vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void PmergeMe::sort_by_pairs(std::vector<int> &vector)
{
	// Base condition: Recursive call ends if `vector` contains only 1 number
	if (vector.size() == 1)
		return;

	// Sort `vector` by pairs of min & max
	// Create new vectors `mins` and `maxs` containing the lower or greater numbers
	PmergeMe::vectit it = vector.begin();
	PmergeMe::vectit it_end = vector.end();
	std::vector<int> maxs;
	std::vector<int> mins;
	while (it + 1 < it_end)
	{
		if (*it > *(it + 1))
		{
			std::iter_swap(it, it + 1);
		}
		mins.push_back(*it);
		maxs.push_back(*(it + 1));
		it += 2;
	}

	// Save number if it was left unpaired
	int unpaired = -1;
	if (vector.size() % 2 != 0)
		unpaired = *it;

	// Recursive call
	std::vector<int> original_maxs = maxs;
	sort_by_pairs(maxs);

	// Insertion logic after the recursive call
	// Build `chain` with all elements from `maxs`
	std::vector<int> chain;
	for (PmergeMe::vectit maxs_it = maxs.begin(); maxs_it < maxs.end(); maxs_it++)
		chain.push_back(*maxs_it);

	// Now add `mins` to chain. Instead of inserting the numbers one by one (mins[0], mins[1], mins[2], mins[3], etc.)
	// we insert them in the order dictated by the Jacobsthal sequence: mins[0], mins[1], mins[3], mins[2], mins[5], mins[4], etc.)
	// However, we don't just push_back each element, we should insert it using binary search.
	std::vector<int> jacob_order = jacobsthal_order(mins.size());
	for (PmergeMe::vectit j_it = jacob_order.begin(); j_it < jacob_order.end(); j_it++)
	{
		PmergeMe::vectit upper_bound = std::find(chain.begin(), chain.end(), original_maxs[*j_it]);
		PmergeMe::vectit insert_pos = std::lower_bound(chain.begin(), upper_bound + 1, mins[*j_it]);
		chain.insert(insert_pos, mins[*j_it]);
	};

	// Insert unpaired number if it exists
	if (unpaired != -1)
	{
		PmergeMe::vectit unpaired_pos = std::lower_bound(chain.begin(), chain.end(), unpaired);
		chain.insert(unpaired_pos, unpaired);
	}

	// Assign `chain` to `vector`, which in turn is the local copy of `maxs`
	vector = chain;
}

// Sort
void PmergeMe::sort()
{
	// clock_t t1 = clock();

	std::cout << "Before: ";
	printVector(v);
	sort_by_pairs(v);
	std::cout << " After: ";
	printVector(v);
	// clock_t t2 = clock();
	// std::cout << std::fixed << ((float)t2 - t1)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}
