#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>

class Character
{
	private:
		// private member variable

	public:
		Character();
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
};

#endif
