#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <limits.h>
# include <sys/time.h>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vector;

		bool	isLongEnough();
		int		randomizer();
		int		signedRandomizer();

	public:
		Span();
		Span(unsigned int capacity);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void			addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			fill();
		void			fill(int num);
		void			printContent();
};

#endif
