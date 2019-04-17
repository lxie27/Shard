#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif
/*! \file
Circle.cpp: the Circle shape.
*/
#include "Circle.h"
#include "Point.h"
#include "SDL2/SDL2_gfxPrimitives.h"

#define PI 3.14
/*!
\brief The deconstructor.
*/
Circle::~Circle() {}
/*!
\brief The constructor
\param cen The center of the Circle
\param rad The radius of the Circle
\returns Circle instance
*/
Circle::Circle(Point cen, double rad) : center(cen), radius(rad) {}

/*!
\brief Updates the Circle's center based on its current force.
*/
void Circle::update() {
	center.x = center.x + getForce().x;
	center.y = center.y + getForce().y;
}
/*!
\brief Gets the area of the Circle.
\returns Returns 2*radius*PI = area.
*/
double Circle::getArea() {
	return radius * radius * PI;
}
/*!
\brief Gets the perimeter of the Circle.
\returns Returns radius * 2 * PI = perimeter.
*/
double Circle::getPerimeter() {
	return radius * 2 * PI;
}

/*!
\brief Gets the AABB of the Circle.
\returns Returns the AABB of the Circle.
*/
AABB Circle::getBB() {
	return bb;
}

/*!
\brief Sets the AABB of the Circle based on its current coordinates.
*/
void Circle::setBB() {
	bb = AABB(radius - center.x, radius - center.y, radius + center.x, radius + center.y);
}

/*!
\brief Renders the Circle, delegated by Shape inheritance.
\param gRenderer The SDL_Renderer of SDLGraphicsProgram.
*/
void Circle::render(SDL_Renderer* gRenderer) {
	aacircleRGBA(gRenderer, center.x, center.y, radius, 0, 255, 0, 255);
	SDL_RenderPresent(gRenderer);
}
