#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>

class MateriaSource
{
	private:
		// private member variable

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
};

#endif
