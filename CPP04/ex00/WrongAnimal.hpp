#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string set_type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		
		std::string		getType() const;
		void			setType(std::string set_type);
		void			makeSound() const;

		virtual	~WrongAnimal();
};

#endif
