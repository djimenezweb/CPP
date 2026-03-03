#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>

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
		void sort();
		void sort_by_pairs(std::vector<int> &vector);
		// void divide_by_pairs();
		// void divide_by_pairs_rec(std::vector<int> parent);
};

#endif
