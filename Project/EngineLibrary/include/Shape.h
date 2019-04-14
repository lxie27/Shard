#ifndef Shape_h
#define Shape_h

#include "Vector2.h"
#include "AABB.h"

class Shape {
public:
	virtual ~Shape()=0;

	virtual double getArea()=0;
	virtual double getPerimeter()=0;
	virtual AABB getBB()=0;
};


#endif
