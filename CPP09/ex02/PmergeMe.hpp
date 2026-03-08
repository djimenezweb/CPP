#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
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
		std::list<int> l;
		PmergeMe();

		// Utils
		void initVector();
		void initList();
		void printVector(std::vector<int> &vector);
		void printList(std::list<int> &list);

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
		void sortList(std::list<int> &list);

		bool isVectorSorted();
		bool isListSorted();

		int &listAt(std::list<int> &list, int n);
};

#endif
