/*! \file
\brief The abstract class for Shapes, implemented by Quad, Triangle, and Circle
*/
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

#include "Shape.h"
#include "Vector2.h"
#include <iostream>

using namespace std;

/*!
\brief Deconstructor.
*/
Shape::~Shape() {}

/*!
\brief Getter for force.
\returns Returns the force, delegated to concrete classes
*/
Vector2 Shape::getForce() {
	return force;
}

/*!
\brief Setter for force.
\param f The force to be set to
*/
void Shape::setForce(Vector2& f) {
	cout << "Shape setting force" << endl;
	force = f;
}

/*!
\brief Adds given force to current force.
\param f The force to be set to
*/
void Shape::addForce(Vector2& f) {
	cout << "Shape adding force" << endl;
	Vector2 v((f.x + force.x), (f.y + force.y));
	setForce(v);
}
