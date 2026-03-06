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
	// std::cout << "mins size = " << max << std::endl;
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

/* 	for (int i = 2; i < max; i++)
	{
		int number = seq[i - 1] + 2 * seq[i - 2];
		seq.push_back(number);
	} */
	// std::cout << "J. seq = ";
	// printVector(seq);
	return (seq);
}

// Return a vector containing the indices representing the order in which the numbers should be inserted.
// These indices are calculated using consecutive pairs as group boundaries.
// For example, to insert 7 numbers the order should be:
//  [1, 1] -> 1
//  [1, 3] -> 3, 2
//  [3, 5] -> 5, 4
// [5, 11] -> 11, 10, 9, 8, 7, 6
// But there are not indices greater or equals than 7 in a 7-element-vector,
// so we clamp it to the actual size.
// We already have inserted item 0 so there's no need to include it.
std::vector<int> PmergeMe::jacobsthal_order(int size)
{
	std::vector<int> vect;
	vect.reserve(size - 1);
	std::vector<int> jacobsthal_seq = jacobsthal_sequence(size);
	// std::cout << "Jac. seq: ";
	// printVector(jacobsthal_seq);

	int i = 0;
	int end;
	int start;
	while (i < size)
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
			if (static_cast<int>(vect.size()) == size - 1)
				break;
			vect.push_back(end);
			end--;
		}
		i++;
	}
	// std::cout << "   Order: ";
	// printVector(vect);
	// std::cout << "\n";
	return (vect);
}
