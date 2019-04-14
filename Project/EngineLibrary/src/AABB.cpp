//This implementation of Axis Aligned Bounding Boxes uses James Randall's 'SimpleVoxelEngines' implementation as a reference
//Their version can be found here: https://github.com/JamesRandall/SimpleVoxelEngine
#include "AABB.h"
#include <algorithm>

AABB::AABB(): min(Vector2(0.0, 0.0)), max(Vector2(0.0, 0.0)) {}

AABB::AABB(Vector2 min, Vector2 max): min(min), max(max) {}

AABB::AABB(double a, double b, double c, double d) : min(Vector2(a, b)), max(Vector2(c, d)) {}

bool AABB::overlaps(AABB& other) {
	return max.x > other.min.x &&
		min.x < other.max.x &&
		max.y > other.min.y &&
		min.y < other.max.y;
}

bool AABB::contains(AABB& other) {
	return other.min.x >= min.x &&
		other.max.x <= max.x &&
		other.min.y >= min.y &&
		other.max.y <= max.y;
}

AABB AABB::intersection(AABB& other) {
	return AABB(Vector2(std::max(min.x, other.min.x), std::max(min.y, other.min.y)),
		Vector2(std::min(max.x, other.max.x), std::min(max.y, other.max.y)));
}

AABB AABB::merge(AABB& other) {
	return AABB(Vector2(std::min(min.x, other.min.x), std::min(min.y, other.min.y)),
		Vector2(std::max(max.x, other.max.x), std::max(max.y, other.max.y)));
}