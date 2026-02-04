#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string set_type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		
		std::string		getType() const;
		void			setType(std::string set_type);
		
		virtual void	makeSound() const = 0;
		virtual			~Animal();
};

#endif
