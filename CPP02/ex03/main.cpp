#include "Fixed.hpp"
#include "Point.hpp"

Fixed triangle_area(Point const a, Point const b, Point const c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

Point	enter_point(std::string label)
{
	float x = 0.0;
	float y = 0.0;

	std::cout << "Point " << label << ": ";
	std::cin >> x >> y;
	Point p(x, y);
	std::cin.ignore(100, '\n');
	return (p);
}

int main(void)
{
	std::cout << "Enter the coordinates of the three ABC vertices "
				 "separated by a space, e.g.: Point A: 1.5 4"
			  << std::endl;
	Point a(enter_point("A"));
	Point b(enter_point("B"));
	Point c(enter_point("C"));
	std::cout << "Enter the coordinates of a point P to check "
				"if it's inside of the triangle" << std::endl;
	Point p(enter_point("P"));

	if (triangle_area(a, b, c) == 0)
	{
		std::cout << "Invalid triangle" << std::endl;
		return (1);
	}

	std::cout << "Point P(" << p.get_x() << ", " << p.get_y() << ")";
	if (bsp(a, b, c, p))
		std::cout << " is inside ";
	else
		std::cout << " is outside ";
	std::cout << "of triangle A(" << a.get_x() << ", " << a.get_y() << "), B("
			  << b.get_x() << ", " << b.get_y() << "), C(" << c.get_x() << ", "
			  << c.get_y() << ")" << std::endl;
}
