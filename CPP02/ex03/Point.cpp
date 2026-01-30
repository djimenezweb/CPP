#include "Point.hpp"

// Default constructor
Point::Point() : x(0) , y (0) {}

// Constructor
Point::Point(const Fixed set_x, const Fixed set_y) : x(set_x), y(set_y) {}

// Destructor
Point::~Point() {}

// Copy constructor
Point::Point(const Point &other)
{
	x = other.x;
	y = other.y;
}

// Copy asignment operator overload `=`
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

// Getter
Fixed Point::get_x() const
{
	return (x);
}

// Getter
Fixed Point::get_y() const
{
	return (y);
}
