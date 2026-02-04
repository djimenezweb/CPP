#ifndef MATERIA_H
# define MATERIA_H

# include <iostream>
# include "Character.hpp"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const &type);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
