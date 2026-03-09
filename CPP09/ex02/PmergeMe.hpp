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

# define ERROR	"\033[31;1mError: \033[0m"

class PmergeMe
{
	private:
		int argc;
		char **argv;
		std::vector<int> v;
		std::list<int> l;
		PmergeMe();

		// Vector
		void	initVector();
		void	printVector(const std::vector<int> &vector) const;
		void	sortVector(std::vector<int> &vector);
		bool	isVectorSorted() const;

		// List
		void	initList();
		void	printList(const std::list<int> &list) const;
		void	sortList(std::list<int> &list);
		bool	isListSorted() const;
		int		listAt(const std::list<int> &list, int n) const;

		// Jacobstahl
		std::vector<int>	jacobsthal_sequence(int max) const;
		std::vector<int>	jacobsthal_order(int size) const;

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void	sort();
};

#endif
