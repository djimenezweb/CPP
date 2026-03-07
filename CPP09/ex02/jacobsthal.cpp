#include "PmergeMe.hpp"

// Return a vector with a Jacobsthal number sequence up to passed maximum.
// sequence -> { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923... }
// max == 1 -> { 0, 1, 1 }
// max == 2 -> { 0, 1, 1, 2 }
// max == 3 -> { 0, 1, 1, 3 }
// max == 4 -> { 0, 1, 1, 3, 4 }
// max == 5 -> { 0, 1, 1, 3, 5 }
// max == 6 -> { 0, 1, 1, 3, 5, 6 }
std::vector<int> PmergeMe::jacobsthal_sequence(int max)
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);

	while (true)
	{
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		if (next >= max)
			break;
		seq.push_back(next);
	}
	seq.push_back(max); // Always end at `max` to cover all elements
	return (seq);
}

// Return a vector containing the indices representing the order in which the numbers should be inserted.
// These indices are calculated using consecutive pairs as group boundaries.
// For example, to insert 7 numbers the order should be { 0, 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6 }:
//  [0, 1] -> 1
//  [1, 1] -> 1
//  [1, 3] -> 3, 2
//  [3, 5] -> 5, 4
// [5, 11] -> 11, 10, 9, 8, 7, 6
// But there are not indices greater or equals than 7 in a 7-element-vector,
// so we clamp it to the actual size: { 0, 1, 3, 2, 5, 4, 6 }.
std::vector<int> PmergeMe::jacobsthal_order(int size)
{
	std::vector<int> vect;
	// vect.reserve(size);	// LO PONEMOS DE NUEVO? size? size +1?
	std::vector<int> jacobsthal_seq = jacobsthal_sequence(size);
	vect.push_back(0);	// Add index 0

	int i = 0;
	int end;
	int start;
	while (i + 1 < static_cast<int>(jacobsthal_seq.size()))
	{
		end = jacobsthal_seq[i + 1];
		start = jacobsthal_seq[i];
		while (start < end)
		{
			if (end > size - 1)
			{
				end--;
				continue;
			}
			if (static_cast<int>(vect.size()) == size)
				break;
			vect.push_back(end);
			end--;
		}
		i++;
	}
	return (vect);
}
