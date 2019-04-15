#include "Quad.h"
#include "Point.h"

Quad::~Quad() {}
Quad::Quad(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

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
