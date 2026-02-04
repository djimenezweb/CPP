#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "Materia.hpp"

# define INV_SIZE 4

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[INV_SIZE];

	public:
		Character();
		Character(std::string name);
		virtual ~Character() {};
		Character(const Character &other);
		Character &operator=(const Character &other);
	
		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};

#endif
