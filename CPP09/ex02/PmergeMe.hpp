#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <limits>

class PmergeMe
{
	private:
		int argc;
		char **argv;
		std::vector<int> v;
		PmergeMe();

		// Utils
		void initVector();
		void printVector(std::vector<int> &vector);

		// Jacobstahl
		std::vector<int> jacobsthal_sequence(int max);
		std::vector<int> jacobsthal_order(int size);

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sort();
		void sortVector(std::vector<int> &vector);

		bool isSorted();

};

#endif
