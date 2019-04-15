#pragma once
#ifndef QUAD_H
#define QUAD_h

#include "Shape.h"
#include "Point.h"

class Quad : public Shape
{
public:
	Point a, b, c, d;
	AABB bb;

	~Quad();
	//Convention: a is the TL point, b is TR point, c is BL point, d is BR point
	Quad(Point a, Point b, Point c, Point d);

	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif