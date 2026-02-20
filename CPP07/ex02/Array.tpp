#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"
# include <exception>

// Default constructor
template <typename T>
Array<T>::Array() : _length(0)
{
	_arr = NULL;
}

// Parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n)
{
	if ((int)n <= 0)
	{
		_length = 0;
		_arr = NULL;
		return;
	}
	_length = n;
	_arr = new T[n];
	for (size_t i = 0; i < n; i++)
		_arr[i] = 0;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other)
{
	_length = other._length;
	_arr = new T[other.size()];
	for (size_t i = 0; i < other.size(); i++)
		_arr[i] = other._arr[i];
}

// Copy assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_length = other._length;
		delete[] _arr;
		_arr = new T[other.size()];
		for (size_t i = 0; i < other.size(); i++)
			_arr[i] = other._arr[i];
	}
	return (*this);
}

// Subscript operator
template <typename T>
T &Array<T>::operator[](int n)
{
	if (n < 0 || n > (signed int)_length - 1)
		throw std::out_of_range("Error: index is out of bounds");
	return (_arr[n]);
}

// Subscript operator (const)
template <typename T>
T &Array<T>::operator[](int n) const
{
	if (n < 0 || n > (signed int)_length - 1)
		throw std::out_of_range("Error: index is out of bounds");
	return (_arr[n]);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	std::cout << "Deleting array of length " << _length << std::endl;
	delete[] _arr;
}

// Getter
template <typename T>
unsigned int Array<T>::size() const
{
	return (_length);
}

#endif
