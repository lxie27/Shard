#include "Triangle.h"
#include "Point.h"
#include <cmath>
#include <algorithm>

using namespace std;

Triangle::~Triangle() {}
Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

void Triangle::update() {
	a.x = a.x + getForce().x;
	b.x = b.x + getForce().x;
	c.x = c.x + getForce().x;

	a.y = a.y + getForce().y;
	b.y = b.y + getForce().y;
	c.y = c.y + getForce().y;
}

double Triangle::getArea() {
	return ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
}

double Triangle::getPerimeter() {
	return (sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0)) +
		sqrt(pow((b.x - c.x), 2.0) + pow((b.y - c.y), 2.0)) +
		sqrt(pow((c.x - a.x), 2.0) + pow((c.y - a.y), 2.0)));
}

AABB Triangle::getBB() {
	return bb;
}

void Triangle::setBB() {
	bb = AABB(min(min(a.x, b.x), c.x),
		min(min(a.y, b.y), c.y),
		max(max(a.x, b.x), c.x),
		max(max(a.y, b.y), b.y));
}
