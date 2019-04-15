#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	Point center;
	double radius;
	AABB bb;

	~Circle();
	Circle(Point cen, double rad);

	void update();

	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif
