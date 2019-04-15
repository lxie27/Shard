#pragma once
#ifndef AABB_H
#define AABB_H

#include "Vector2.h"

class AABB {
public:
	Vector2 min;
	Vector2 max;

	~AABB() {};
	AABB();
	AABB(Vector2 min, Vector2 max);
	AABB(double a, double b, double c, double d);

	bool overlaps(AABB& other);
	bool contains(AABB& other);

	AABB intersection(AABB& other);
	AABB merge(AABB& other);
};

#endif
