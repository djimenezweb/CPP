#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	if (bsp(Point(1, 2), Point(3, 4), Point(5, 2), Point(3, 3)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;

	if (bsp(Point(1, 2), Point(3, 4), Point(5, 2), Point(5, 5)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
}
