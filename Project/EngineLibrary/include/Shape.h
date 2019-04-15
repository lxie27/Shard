#pragma once
#ifndef	SHAPE_H
#define SHAPE_H

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
