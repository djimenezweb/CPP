#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_length;
		T				*_arr;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int n);

		unsigned int size() const;
};

# include "Array.tpp"

#endif
