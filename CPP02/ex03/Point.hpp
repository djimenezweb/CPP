#ifndef POINT_H
#define POINT_H

# include "Fixed.hpp"

class Point
{
private:
	Fixed	x;
	Fixed	y;

public:
	Point();
	Point(const Fixed set_x, const Fixed set_y);
	~Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	Fixed get_x() const;
	Fixed get_y() const;
};

#endif