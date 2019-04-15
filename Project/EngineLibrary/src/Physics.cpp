#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

#include "Shape.h"
#include "Physics.h"

#define GRAVITY -9.81
#define TERMINAL_VELOCITY 40

using namespace std;

Physics::Physics(vector<Shape*> s) : shapes(s) {}

vector<Shape*> Physics::getShapes() {
	return shapes;
}

void Physics::addShape(Shape* s) {
	shapes.push_back(s);
}

void Physics::update() {
	vector<Shape*>::iterator it;

	for (it = shapes.begin(); it != shapes.end(); it++) {
		//gravity always pulls shapes down by accelerating them 9.81 unless at terminal velocity
		if (abs((*it)->getForce().y) < TERMINAL_VELOCITY) {
			(*it)->addForce(Vector2(0.0, GRAVITY));
		}
	}
}

