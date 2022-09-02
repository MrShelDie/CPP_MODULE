#include "Point.hpp"

/* 
** Determines whether a point is in a triangle by the vector method.
** https://www.youtube.com/watch?v=HYAgJN3x4GA
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	const float ax = a.getX().toFloat();
	const float ay = a.getY().toFloat();

	const float bx = b.getX().toFloat();
	const float by = b.getY().toFloat();

	const float cx = c.getX().toFloat();
	const float cy = c.getY().toFloat();

	const float px = point.getX().toFloat();
	const float py = point.getY().toFloat();

	const float w1 = (ax*(cy - ay) + (py - ay)*(cx - ax) - px*(cy - ay))
						/ ((by - ay)*(cx - ax) - (bx - ax)*(cy - ay));

	const float w2 = (py - ay - w1*(by - ay)) / (cy - ay);

	return w1 > 0 && w2 > 0 && (w1 + w2) < 1;
} 