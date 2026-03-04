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
	int					number;
	std::string			str;

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

void PmergeMe::printVector(std::vector<int> &vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void PmergeMe::printSortedPairs(std::vector<int> &vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i % 2 != 0)
			std::cout << "\033[0m" << vector[i] << "\033[0m" << " ";
		else
			std::cout << "\033[33;1m" << vector[i] << "\033[0m" << " ";
	}
	std::cout << "}" << std::endl;
}

// Generate Jacobsthal numbers up to a given limit
// Jacobsthal: 0, 1, 1, 3, 5, 11, 21, 43, 85...
// We use it to determine the ORDER in which we insert elements
std::vector<int> jacobsthal_sequence(int n)
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (true)
	{
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		if (next >= n)
			break;
		seq.push_back(next);
	}
	seq.push_back(n); // Always end at n to cover all elements
	return seq;
}

// Binary search: find insertion point for 'val' in sorted range [begin, end)
// We know val <= paired_max, so we can limit the search range
std::vector<int>::iterator binary_search_insert(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end,
	int val)
{
	std::vector<int>::iterator lo = begin;
	std::vector<int>::iterator hi = end;

	while (lo < hi)
	{
		std::vector<int>::iterator mid = lo + (hi - lo) / 2;
		if (*mid < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo; // Position to insert before
}

void PmergeMe::mergeBack(std::vector<int> &vec, std::vector<int> &mins, std::vector<int> &maxs, int unpaired)
{
	// Step 3: Build the 'chain' — this is the sequence we'll insert into.
	// We know mins[0] <= maxs[0] (its sorted pair), so mins[0] can be
	// prepended to the front for free (0 comparisons needed).
	std::vector<int> chain;
	chain.push_back(mins[0]); // Free insertion: guaranteed smallest

	for (std::vector<int>::iterator it = maxs.begin(); it < maxs.end(); it++)
		chain.push_back(*it);

	// Step 4: Insert remaining mins using Jacobsthal insertion order.
	// Why Jacobsthal? It minimizes worst-case comparisons by inserting
	// in an order that keeps binary search ranges as powers of 2.

	int total_mins = (int)mins.size();
	std::vector<int> jac = jacobsthal_sequence(total_mins);

	std::vector<bool> inserted(total_mins, false);
	inserted[0] = true; // mins[0] already inserted above

	for (int k = 1; k < (int)jac.size(); k++)
	{
		// Insert from jac[k]-1 down to jac[k-1] (Jacobsthal group, reversed)
		// This reverse order is key: inserting the larger one first
		// tightens the binary search bound for the smaller ones
		int group_end = std::min(jac[k], total_mins) - 1;
		int group_start = jac[k - 1];

		for (int i = group_end; i >= group_start; i--)
		{
			if (inserted[i])
				continue;
			inserted[i] = true;

			int val = mins[i];

			// KEY OPTIMIZATION: mins[i] <= maxs[i] (its pair partner).
			// Find where maxs[i] ended up in the chain — binary search
			// only needs to go up to that position, not the full chain.
			// This halves the effective search space.
			std::vector<int>::iterator pair_partner_pos =
				std::find(chain.begin(), chain.end(), maxs[i]);

			std::vector<int>::iterator insert_pos =
				binary_search_insert(chain.begin(), pair_partner_pos + 1, val);

			chain.insert(insert_pos, val);
		}
	}

	// Step 5: Insert straggler (if any) — it has no pair upper-bound,
	// so binary search over the full chain
	if (unpaired != -1)
	{
		std::vector<int>::iterator insert_pos =
			binary_search_insert(chain.begin(), chain.end(), unpaired);
		chain.insert(insert_pos, unpaired);
	}

	// Step 6: Write sorted result back into original vector
	vec = chain;
}

void PmergeMe::sort_by_pairs(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int>::iterator it = vec.begin();
	std::vector<int> maxs;
	std::vector<int> mins;

	// Step 1: Split into pairs, pushing larger into maxs, smaller into mins
	// Each mins[i] is guaranteed to be <= maxs[i] (its pair partner)
	while (it + 1 < vec.end())
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		mins.push_back(*it);
		maxs.push_back(*(it + 1));
		it += 2;
	}

	// Unpaired element — treat it like a "min" with no partner
	int unpaired = -1;
	if (vec.size() % 2 != 0)
		unpaired = *it;

	// Step 2: Recursively sort the larger elements (maxs)
	// After this, maxs is fully sorted
	sort_by_pairs(maxs);
	mergeBack(vec, mins, maxs, unpaired);
}

// Sort
void PmergeMe::sort()
{
	clock_t t1 = clock();
	std::cout << "Vector size: " << v.size() << std::endl;
	printVector(v);
	sort_by_pairs(v);
	clock_t t2 = clock();
	std::cout << std::fixed << ((float)t2 - t1)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	printVector(v);
}
