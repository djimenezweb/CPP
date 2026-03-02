#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>

class PmergeMe
{
	private:
		char **argv;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
};

#endif
