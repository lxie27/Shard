#include "Circle.h"
#include "Point.h"

#define PI 3.14

Circle::~Circle() {}
Circle::Circle(Point cen, double rad) : center(cen), radius(rad) {}

double Circle::getArea() {
	return radius * radius * PI;
}

double Circle::getPerimeter() {
	return radius * 2 * PI;
}

AABB Circle::getBB() {
	return bb;
}

void Circle::setBB() {
	bb = AABB(radius - center.x, radius + center.x, radius - center.y, radius + center.y);
}