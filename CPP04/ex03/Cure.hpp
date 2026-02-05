#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "Materia.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
