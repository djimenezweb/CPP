#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>

class AMateria
{
	private:
		// private member variable

	public:
		AMateria();
		~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
};

#endif
