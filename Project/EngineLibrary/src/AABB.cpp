//This implementation of Axis Aligned Bounding Boxes uses James Randall's 'SimpleVoxelEngines' implementation as a reference
//Their version can be found here: https://github.com/JamesRandall/SimpleVoxelEngine

/*! \file
\brief Axis-Aligned Bounding Box for collisions.
*/
#include "AABB.h"
#include <algorithm>

/*!
\brief The constructor.
\returns The instance of the AABB.
*/
AABB::AABB(): min(Vector2(0.0, 0.0)), max(Vector2(0.0, 0.0)) {}

/*!
\brief The constructor given 2 Vector2's.
\param min The min x and y bounding axis.
\param max The max x and y bounding axis.
\returns The instance of the AABB.
*/
AABB::AABB(Vector2 min, Vector2 max): min(min), max(max) {}

/*!
\brief The constructor given 4 doubles.
\param a The min x bounding axis.
\param a The min y bounding axis.
\param a The max x bounding axis.
\param a The max y bounding axis.
\returns The instance of the AABB.
*/
AABB::AABB(double a, double b, double c, double d) : min(Vector2(a, b)), max(Vector2(c, d)) {}

/*!
\brief Checks for overlap between two AABBs.
\param other The other AABB to compare to.
\returns Returns false if no overlap, 1 otherwise.
*/
bool AABB::overlaps(AABB& other) {
	return max.x > other.min.x &&
		min.x < other.max.x &&
		max.y > other.min.y &&
		min.y < other.max.y;
}

/*!
\brief Checks for containment between two AABBs.
\param other The other AABB to compare to.
\returns Returns false if other is contained in this AABB, 1 otherwise.
*/
bool AABB::contains(AABB& other) {
	return other.min.x >= min.x &&
		other.max.x <= max.x &&
		other.min.y >= min.y &&
		other.max.y <= max.y;
}

/*!
\brief Gets the intersection between two AABBs.
\param other The other AABB to compare to.
\returns Returns AABB of the intersection.
*/
AABB AABB::intersection(AABB& other) {
	return AABB(Vector2(std::max(min.x, other.min.x), std::max(min.y, other.min.y)),
		Vector2(std::min(max.x, other.max.x), std::min(max.y, other.max.y)));
}

/*!
\brief Gets the total AABB between two AABBs.
\param other The other AABB to compare to.
\returns Returns AABB of the total AABBs.
*/
AABB AABB::merge(AABB& other) {
	return AABB(Vector2(std::min(min.x, other.min.x), std::min(min.y, other.min.y)),
		Vector2(std::max(max.x, other.max.x), std::max(max.y, other.max.y)));
}