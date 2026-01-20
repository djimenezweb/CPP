class Fixed
{
private:
	int			value;
	static int	fr_bits; // const ??

public:
	// default constructor
	// copy constructor
	// copy assignment operator overlad
	// destructor
	int	getRawBits(void) const;
	int	setRawBits(int const raw);
}

