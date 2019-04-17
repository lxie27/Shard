#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include <iterator>

#include "Vector2.h"
#include "Shape.h"
#include "Quad.h"
#include "Circle.h"
#include "Triangle.h"

/*----Class*/
class Physics
{
public:
	~Physics() {};
	Physics();
	Physics(std::vector<Shape*> shapes);

	/*Getter*/
	std::vector<Shape*> getShapes();

	/*Adders*/
	void addShape(Shape* s);
	void addForce(double force);

	//void addShape(Triangle* t);
	//void addShape(Quad* q);
	//void addShape(Circle* c);
	void update();

private:
	std::vector<Shape*> shapes;
};


#endif
