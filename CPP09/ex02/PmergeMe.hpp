#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>

class PmergeMe
{
	private:
		// private member variable

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
};

#endif
