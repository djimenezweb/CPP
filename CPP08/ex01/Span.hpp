#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>
# include <exception>
# include <vector>
# include <algorithm>


class Span
{
	private:
		unsigned int N;
		std::vector<int> vector;
		int getMin();
		int getMax();
		bool isLongEnough();
		int	randomizer();

	public:
		Span();
		Span(unsigned int capacity);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void fill();
};

#endif
