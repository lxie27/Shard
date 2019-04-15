#include "Rectangle.h"
#include "Point.h"

Rectangle::~Rectangle() {}
Rectangle::Rectangle(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

double Rectangle::getArea() {
	return (a.y - c.y) * (b.x - a.x);
}

double Rectangle::getPerimeter() {
	return (b.x - a.x) + (d.y - b.y) + (d.x - c.x) + (c.y - a.y);
}

AABB Rectangle::getBB() {
	return bb;
}

void Rectangle::setBB() {
	bb = AABB(a.x, a.y, d.x, d.y);
}
