#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "Materia.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		// private member variable

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif
