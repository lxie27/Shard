#include "Shape.h"
#include "Vector2.h"
Shape::~Shape() {}

Vector2 Shape::getForce() {
	return force;
}

void Shape::setForce(Vector2 f) {
	force = f;
}

void Shape::addForce(Vector2 f) {
	setForce(Vector2((f.x + getForce().x), (f.y + getForce().y)));
}