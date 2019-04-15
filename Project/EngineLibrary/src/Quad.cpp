#include "Quad.h"
#include "Point.h"
Quad::~Quad() {}
Quad::Quad(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

//Quads are ultra-rigid; all points are shifted by force equally
void Quad::update() {
	a.x = a.x + getForce().x;
	b.x = b.x + getForce().x;
	c.x = c.x + getForce().x;
	d.x = d.x + getForce().x;

	a.y = a.y + getForce().y;
	b.y = b.y + getForce().y;
	c.y = c.y + getForce().y;
	d.y = d.y + getForce().y;
}

double Quad::getArea() {
	return (a.y - c.y) * (b.x - a.x);
}

double Quad::getPerimeter() {
	return (b.x - a.x) + (d.y - b.y) + (d.x - c.x) + (c.y - a.y);
}

AABB Quad::getBB() {
	return bb;
}

void Quad::setBB() {
	bb = AABB(a.x, a.y, d.x, d.y);
}
