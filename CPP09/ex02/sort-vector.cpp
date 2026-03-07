#include "PmergeMe.hpp"

void PmergeMe::sortVector(std::vector<int> &vector)
{
	// Base condition: Recursive call ends if `vector` contains only 1 number
	if (vector.size() == 1)
		return;

	// Sort `vector` by pairs of min & max
	// Create new vectors `mins` and `maxs` containing the lower or greater numbers of each pair
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator it_end = vector.end();
	std::vector<int> maxs;
	std::vector<int> mins;
	while (it + 1 < it_end)
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		mins.push_back(*it);
		maxs.push_back(*(it + 1));
		it += 2;
	}

	// Save number if it was left unpaired
	int unpaired = -1;
	if (vector.size() % 2 != 0)
		unpaired = *it;

	// Save copy to preserve original order
	std::vector<int> original_maxs = maxs;

	// Recursive call
	sortVector(maxs);

	// After recursive call, build `chain` with all elements from `maxs`
	std::vector<int> chain;
	for (std::vector<int>::iterator maxs_it = maxs.begin(); maxs_it < maxs.end(); maxs_it++)
		chain.push_back(*maxs_it);

	// Insert `mins` to `chain`. Instead of inserting the numbers one by one (mins[0], mins[1], mins[2] ...)
	// we insert them in the order dictated by the Jacobsthal sequence: mins[0], mins[1], mins[3], mins[2], mins[5], mins[4] ...)
	std::vector<int> jacob_order = jacobsthal_order(mins.size());
	for (std::vector<int>::iterator j_it = jacob_order.begin(); j_it < jacob_order.end(); j_it++)
	{
		std::vector<int>::iterator upper_bound = std::find(chain.begin(), chain.end(), original_maxs[*j_it]);
		std::vector<int>::iterator insert_pos = std::lower_bound(chain.begin(), upper_bound + 1, mins[*j_it]);
		chain.insert(insert_pos, mins[*j_it]);
	};

	// Insert unpaired number if any
	if (unpaired != -1)
	{
		std::vector<int>::iterator unpaired_pos = std::lower_bound(chain.begin(), chain.end(), unpaired);
		chain.insert(unpaired_pos, unpaired);
	}

	// Assign `chain` to `vector`, which in turn is the local copy of `maxs`
	vector = chain;
}
