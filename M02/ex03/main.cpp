#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);

	std::cout << "triangle (0, 0) (1, 0) (0, 1)\n";

	std::cout << "(0, 0) is in the triangle: " << bsp(a, b, c, Point(0, 0)) << "\n";
	std::cout << "(1, 0) is in the triangle: " << bsp(a, b, c, Point(1, 0)) << "\n";
	std::cout << "(0, 1) is in the triangle: " << bsp(a, b, c, Point(0, 1)) << "\n";
	std::cout << "(0.25, 0.25) is in the triangle: " << bsp(a, b, c, Point(0.25, 0.25)) << "\n";
	std::cout << "(-0.25, 0.25) is in the triangle: " << bsp(a, b, c, Point(-0.25, 0.25)) << "\n";
	std::cout << "(0.25, -0.25) is in the triangle: " << bsp(a, b, c, Point(0.25, -0.25)) << "\n";

	return 0;
}