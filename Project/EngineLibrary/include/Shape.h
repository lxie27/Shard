#pragma once
#ifndef	SHAPE_H
#define SHAPE_H

#include "Vector2.h"
#include "AABB.h"

class Shape {
public:
	virtual ~Shape()=0;

	virtual void update() = 0;

	virtual Vector2 getForce();
	virtual void setForce(Vector2 f);
	virtual void addForce(Vector2 f);

	virtual double getArea()=0;	
	virtual double getPerimeter()=0;
	virtual AABB getBB()=0;

private:
	Vector2 force;
	
};


#endif
