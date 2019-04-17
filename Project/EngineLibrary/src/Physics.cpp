#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>
#include <iostream>
/*! \file
Physics.cpp: the Physics engine.
*/
#include "Shape.h"
#include "Quad.h"
#include "Triangle.h"
#include "Circle.h"
#include "Physics.h"

#define GRAVITY -9.81
#define TERMINAL_VELOCITY 40

using namespace std;

/*!
\brief The constructor.
\returns Physics instance.
*/
Physics::Physics() 
{
	vector<Shape*> shapes;
}

/*!
\brief The constructor.
\param s The vector of pointers to shapes.
\returns Physics instance.
*/
Physics::Physics(vector<Shape*> s) : shapes(s) {}

/*!
\brief Gets the vector of pointers of shape.
\returns Returns shapes.
*/
vector<Shape*> Physics::getShapes() {
	return shapes;
}

/*!
\brief Adds the pointer to a Shape to shapes.
*/
void Physics::addShape(Shape* s) {
	shapes.push_back(s);
}

/*
void Physics::addShape(Triangle* t) {
	addShape(t);
}
void Physics::(Quad* q) {
	addShape(q);
}
void Physics::addShape(Circle* c) {
	addShape(c);
}
*/

/*!
\brief Updates all shapes in the engine based on their force; delegates to the Shape implementation
*/
void Physics::update() {
	//cout << "update force" << endl;

	for (auto s : getShapes()) {
		//cout << "force loop" << endl;

		if (abs(s->force.y) < TERMINAL_VELOCITY) {
			Vector2 v(0.0, GRAVITY);
			//s->addForce(v);
		}
	}
}

