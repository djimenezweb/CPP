#include "Span.hpp"

// Default constructor
Span::Span() : N(0) {}

// Parameterized constructor
Span::Span(unsigned int capacity)
{
	if ((int)capacity < 0)
		throw (std::runtime_error("Not a valid number"));
	N = capacity;
	vector.reserve(capacity);
}

// Copy constructor
Span::Span(const Span &other)
{
	N = other.N;
	vector = other.vector;
}

// Copy assignment operator
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		vector = other.vector;
	}
	return (*this);
}

// Destructor
Span::~Span() {}

// Public member functions

void Span::printContent()
{
	for (size_t i = 0; i < N; i++)
		std::cout << i << ": " << vector[i] << std::endl;
}

void Span::fill()
{
	std::cout << "Filling vector of size " << N << " with random numbers" << std::endl;
	for (size_t i = 0; i < N; i++)
		vector.push_back(signedRandomizer());
}

void Span::fill(int num)
{
	std::cout << "Filling vector of size " << N << " with " << num << std::endl;
	vector.assign(N, num);
}

void Span::addNumber(int num)
{
	if (vector.size() == N )
		throw (std::runtime_error("Can't add a number beyond max capacity"));
	vector.push_back(num);
}

unsigned int Span::shortestSpan()
{
	isLongEnough();

	int shortest = INT_MAX;
	int difference = INT_MAX;
	std::vector<int> sorted_v = vector;
	std::sort(sorted_v.begin(), sorted_v.end());

	std::vector<int>::iterator it = sorted_v.begin();
	while(it != (sorted_v.end() - 1))
	{
		difference = *(it + 1) - *it;
		shortest = (difference < shortest) ? difference : shortest;
		it++;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	isLongEnough();

	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	min = std::min_element(vector.begin(), vector.end());
	max = std::max_element(vector.begin(), vector.end());
	return (*max - *min);
}

// Auxiliary functions

bool Span::isLongEnough()
{
	if (vector.empty())
		throw (std::runtime_error("No span can be found in an empty array"));
	if (vector.size() == 1)
		throw (std::runtime_error("No span can be found in a single element array"));
	return (true);
}

int	Span::randomizer()
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	std::srand(tv.tv_sec ^ tv.tv_usec);

	int random_number = std::rand();
	return (random_number);
}

int Span::signedRandomizer()
{
	int sign = randomizer() % 2 ? 1 : -1;
	int random_number = sign * randomizer();
	return (random_number);
}
