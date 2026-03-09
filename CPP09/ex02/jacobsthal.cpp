#include "PmergeMe.hpp"

// Return a vector with a Jacobsthal number sequence up to passed maximum.
// { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923... }
std::vector<int> PmergeMe::jacobsthal_sequence(int max) const
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);

	while (true)
	{
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		seq.push_back(next);
		if (next >= max)
			break;
	}
	return (seq);
}

/* Return a vector containing the indices representing the order in which the numbers should be inserted.
These indices are calculated using consecutive pairs as group boundaries.
	[1, 1]  -> 1
	[1, 3]  -> 3, 2
	[3, 5]  -> 5, 4
	[5, 11] -> 11, 10, 9, 8, 7, 6
	etc.
For example, to insert 7 numbers the order should be { 0, 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6 }
But there are not indices greater or equals than 7 in a 7-element-vector,
so we clamp it to the actual size: { 0, 1, 3, 2, 5, 4, 6 }. */
std::vector<int> PmergeMe::jacobsthal_order(size_t size) const
{
	std::vector<int> indices;
	std::vector<int> jacobsthal_seq = jacobsthal_sequence(size);

	indices.reserve(size);
	indices.push_back(0);

	int i = 0;
	int end;
	int start;
	while (i + 1 < static_cast<int>(jacobsthal_seq.size()))
	{
		end = jacobsthal_seq[i + 1];
		start = jacobsthal_seq[i];
		while (start < end)
		{
			if (static_cast<size_t>(end) > size - 1)
			{
				end--;
				continue;
			}
			if (indices.size() == size)
				break;
			indices.push_back(end);
			end--;
		}
		i++;
	}
	return (indices);
}
