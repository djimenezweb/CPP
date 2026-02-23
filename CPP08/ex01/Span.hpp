#ifndef SPAN_H
# define SPAN_H

# include <iostream>

class Span
{
	private:
		// private member variable

	public:
		Span();
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
};

#endif
