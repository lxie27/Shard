#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include <iterator>

#include "Vector2.h"
#include "Shape.h"
#include "Quad.h"
#include "Circle.h"


class Physics
{
public:
	~Physics() {};
	Physics(std::vector<Shape*> shapes);

	std::vector<Shape*> getShapes();
	void addShape(Shape* s);

	void update();
	void addForce(double force);

private:
	std::vector<Shape*> shapes;
};


#endif
