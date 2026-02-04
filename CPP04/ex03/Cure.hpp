#ifndef CURE_H
# define CURE_H

# include <iostream>

class Cure
{
	private:
		// private member variable

	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
};

#endif
