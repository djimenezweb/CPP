#include "Materia.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);

	std::cout << "START Copy me2" << std::endl;
	ICharacter* me2 = new Character(*static_cast<Character*>(me));
	std::cout << "END Copy me2" << std::endl;

	std::cout << "START Copy assignment me3" << std::endl;
	Character* me3 = new Character("me3");
	*me3 = *static_cast<Character*>(me);
	std::cout << "END Copy assignment me3" << std::endl;


	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	me2->equip(tmp2);
	tmp2 = src->createMateria("ice");
	me2->equip(tmp2);
	me2->unequip(0);
	me2->unequip(1);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete me2;
	delete me3;
	delete src;

	return (0);
}
