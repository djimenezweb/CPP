#include "MutantStack.hpp"

int main()
{
	std::cout << "== TEST 1 == MutantStack ==" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top() = " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack.size() = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(321);
	mstack.push(9);
	mstack.push(46);
	mstack.push(62);
	mstack.push(214);
	mstack.push(13);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator it_end = mstack.end();

	++it;
	--it;

	while (it != it_end)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << "== TEST 2 == Reverse MutantStack ==" << std::endl;

	MutantStack<int> copy_mstack;
	copy_mstack = mstack;

	MutantStack<int>::reverse_iterator rev_it = copy_mstack.rbegin();
	MutantStack<int>::reverse_iterator rev_it_end = copy_mstack.rend();

	while (rev_it != rev_it_end)
	{
		std::cout << *rev_it << std::endl;
		++rev_it;
	}

	std::cout << std::endl << "== TEST 3 == Constant MutantStack ==" << std::endl;

	const MutantStack<int> const_mstack(mstack);

	MutantStack<int>::const_iterator const_it = const_mstack.begin();
	MutantStack<int>::const_iterator const_it_end = const_mstack.end();

	while (const_it != const_it_end)
	{
		std::cout << *const_it << std::endl;
		++const_it;
	}

	std::cout << std::endl << "== TEST 4 == Reverse constant MutantStack ==" << std::endl;

	MutantStack<int>::const_reverse_iterator const_rev_it = const_mstack.rbegin();
	MutantStack<int>::const_reverse_iterator const_rev_it_end = const_mstack.rend();

	while (const_rev_it != const_rev_it_end)
	{
		std::cout << *const_rev_it << std::endl;
		++const_rev_it;
	}

	return 0;
}
