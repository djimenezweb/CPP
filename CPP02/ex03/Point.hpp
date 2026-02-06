#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;

public:
	Point();
	~Point();
	Point(const Fixed set_x, const Fixed set_y);
	Point(const Point &other);
	Point &operator=(const Point &other);

	Fixed get_x() const;
	Fixed get_y() const;
};

#endif
