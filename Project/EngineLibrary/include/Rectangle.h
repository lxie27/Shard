#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape
{
public:
	Point a, b, c, d;
	AABB bb;

	~Rectangle();
	//Convention: a is the TL point, b is TR point, c is BL point, d is BR point
	Rectangle(Point a, Point b, Point c, Point d);

	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif
