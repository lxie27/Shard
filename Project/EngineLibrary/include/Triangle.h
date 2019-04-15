#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape 
{
public:
	Point a, b, c;
	AABB bb;

	~Triangle();
	Triangle(Point a, Point b, Point c);
	
	void update();

	double getArea();
	double getPerimeter();

	AABB getBB();
	void setBB();
};

#endif