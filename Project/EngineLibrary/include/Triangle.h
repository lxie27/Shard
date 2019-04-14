#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape 
{
public:
	Point a, b, c;
	AABB bb;

	~Triangle();
	Triangle(Point a, Point b, Point c);
	
	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif