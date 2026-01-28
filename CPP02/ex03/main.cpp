#include "Fixed.hpp"
#include "Point.hpp"

Fixed triangle_area(Point const a, Point const b, Point const c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	float x = 0.0;
	float y = 0.0;

	std::cout << "Enter the coordinates of the three ABC vertices "
				 "separated by a space, e.g.: Point A: 1.5 4"
			  << std::endl;
	std::cout << "Point A: ";
	std::cin >> x >> y;
	Point a(x, y);
	std::cin.ignore(100, '\n');
	std::cout << "Point B: ";
	std::cin >> x >> y;
	Point b(x, y);
	std::cin.ignore(100, '\n');
	std::cout << "Point C: ";
	std::cin >> x >> y;
	Point c(x, y);
	std::cin.ignore(100, '\n');
	std::cout << "Enter the coordinates of a point P to "
				 "check if it's inside of the triangle"
			  << std::endl
			  << "Point P: ";
	std::cin >> x >> y;
	Point p(x, y);
	std::cin.ignore(100, '\n');
	std::cout << std::endl;

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
