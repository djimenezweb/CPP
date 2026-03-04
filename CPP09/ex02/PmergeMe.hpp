#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <ctime>

class PmergeMe
{
	private:
		int argc;
		char **argv;
		std::vector<int> v;
		PmergeMe();

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void initVector();
		void printVector(std::vector<int> &vector);
		void printSortedPairs(std::vector<int> &vector);
		void mergeBack(std::vector<int> &vec, std::vector<int> &mins, std::vector<int> &maxs, int unpaired);
		void sort();
		void sort_by_pairs(std::vector<int> &vector);
};

#endif
