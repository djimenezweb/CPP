#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "Materia.hpp"

# define INV_SIZE 4

class AMateria;

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
		AMateria	**used;

	public:
		Character();
		Character(std::string name);
		//virtual ~Character() {}; //???
		~Character(); 			//???
		Character(const Character &other);
		Character &operator=(const Character &other);
	
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		void print_inventory();
};

#endif
