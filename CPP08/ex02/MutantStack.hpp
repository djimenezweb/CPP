#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

#endif
