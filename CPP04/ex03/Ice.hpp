#ifndef ICE_H
# define ICE_H

# include <iostream>

class Ice
{
	private:
		// private member variable

	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
};

#endif
