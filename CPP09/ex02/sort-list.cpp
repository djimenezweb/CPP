#include "PmergeMe.hpp"

// Subscript operator
int& PmergeMe::listAt(std::list<int> &list, int n)
{
	std::list<int>::iterator it = list.begin();
	std::advance(it, n);
	return (*it);
}

void PmergeMe::sortList(std::list<int> &list)
{
	if (list.size() == 1)
		return;

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator it_next = it;
	std::advance(it_next, 1);
	std::list<int>::iterator it_end = list.end();
	std::list<int> maxs;
	std::list<int> mins;
	while (it_next != it_end)
	{
		if (*it > *(it_next))
			std::iter_swap(it, it_next);
		mins.push_back(*it);
		maxs.push_back(*(it_next));
		std::advance(it, 2);
		if (it == it_end)
			break;
		it_next = it;
		std::advance(it_next, 1);
	}

	int unpaired = -1;
	if (list.size() % 2 != 0)
		unpaired = *it;

	std::list<int> original_maxs = maxs;

	sortList(maxs);

	std::list<int> chain;
	for (std::list<int>::iterator maxs_it = maxs.begin(); maxs_it != maxs.end(); maxs_it++)
		chain.push_back(*maxs_it);

	std::vector<int> jacob_order = jacobsthal_order(mins.size());
	for (std::vector<int>::iterator j_it = jacob_order.begin(); j_it < jacob_order.end(); j_it++)
	{
		std::list<int>::iterator upper_bound = std::find(chain.begin(), chain.end(), listAt(original_maxs, *j_it));
		std::list<int>::iterator insert_pos = std::lower_bound(chain.begin(), ++upper_bound, listAt(mins, *j_it));
		chain.insert(insert_pos, listAt(mins, *j_it));
	};

	if (unpaired != -1)
	{
		std::list<int>::iterator unpaired_pos = std::lower_bound(chain.begin(), chain.end(), unpaired);
		chain.insert(unpaired_pos, unpaired);
	}

	list = chain;
}
