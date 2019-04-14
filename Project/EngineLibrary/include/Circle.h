#ifndef Circle_h
#define Circle_h

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

	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif
