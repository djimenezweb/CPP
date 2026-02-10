#ifndef FORM_H
# define FORM_H

# include <iostream>

class Form
{
	private:
		// private member variable

	public:
		Form();
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
};

#endif
