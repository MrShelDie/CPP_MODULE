#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class Point {

public:

	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	~Point();

	Point& operator=(const Point& other);

	const Fixed& getX() const;
	const Fixed& getY() const;


private:

	const Fixed x;
	const Fixed y;

};

#endif