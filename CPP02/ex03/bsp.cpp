#include "Point.hpp"
#include "Fixed.hpp"

// https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
Fixed triangle_area(Point const a, Point const b, Point const c)
{
	Point AB(b.get_x() - a.get_x(), b.get_y() - a.get_y());
	Point AC(c.get_x() - a.get_x(), c.get_y() - a.get_y());
	Fixed cross_product((AB.get_x() * AC.get_y()) - (AB.get_y() * AC.get_x()));
	Fixed absolute = Fixed::abs(cross_product) / 2;
	return (absolute);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total_area;
	Fixed sub_areas;

	total_area = triangle_area(a, b, c);
	sub_areas = triangle_area(a, b, point) + triangle_area(a, c, point) +
				triangle_area(b, c, point);
	if (sub_areas == total_area)
		return (true);
	return (false);
}
