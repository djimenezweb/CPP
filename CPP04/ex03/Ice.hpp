#ifndef ICE_H
# define ICE_H

# include <iostream>
# include "Materia.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
