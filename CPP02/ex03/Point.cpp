#include "Point.hpp"

Point::Point() : x(0) , y (0) {}

Point::Point(const Fixed set_x, const Fixed set_y) : x(set_x), y(set_y) {}

Point::~Point() {}

// Copy constructor
Point::Point(const Point &other)
{
	*this  = other;
}

// Copy asignment operator overload
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

Fixed Point::get_x() const
{
	return (x);
}

Fixed Point::get_y() const
{
	return (y);
}
