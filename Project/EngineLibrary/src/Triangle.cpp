#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif
/*! \file
Triangle.cpp: the Triangle shape.
*/
#include "Triangle.h"
#include "Point.h"
#include <cmath>
#include <algorithm>

using namespace std;

/*!
\brief The deconstructor.
*/
Triangle::~Triangle() {}

/*!
\brief The constructor
\param a The one corner of the Triangle
\param b The one corner of the Triangle
\param c The one corner of the Triangle
\returns Triangle instance
*/
Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c)
{
	Vector2 v = Vector2(0.0, 0.0);
	setForce(v);
}

/*!
\brief Updates the Quad's Points based on its current force.
*/
void Triangle::update() {
	a.x = a.x + getForce().x;
	b.x = b.x + getForce().x;
	c.x = c.x + getForce().x;

	a.y = a.y + getForce().y;
	b.y = b.y + getForce().y;
	c.y = c.y + getForce().y;
}
/*!
\brief Gets the area of the Quad.
\returns Returns area.
*/
double Triangle::getArea() {
	return ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
}
/*!
\brief Gets the perimeter of the Triangle.
\returns Returns perimeter.
*/
double Triangle::getPerimeter() {
	return (sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0)) +
		sqrt(pow((b.x - c.x), 2.0) + pow((b.y - c.y), 2.0)) +
		sqrt(pow((c.x - a.x), 2.0) + pow((c.y - a.y), 2.0)));
}
/*!
\brief Gets the AABB of the Triangle.
\returns Returns the AABB of the Triangle.
*/
AABB Triangle::getBB() {
	return bb;
}
/*!
\brief Sets the AABB of the Triangle based on its current coordinates.
*/
void Triangle::setBB() {
	bb = AABB(min(min(a.x, b.x), c.x),
		min(min(a.y, b.y), c.y),
		max(max(a.x, b.x), c.x),
		max(max(a.y, b.y), b.y));
}
/*!
\brief Renders the Triangle, delegated by Shape inheritance.
\param gRenderer The SDL_Renderer of SDLGraphicsProgram.
*/
void Triangle::render(SDL_Renderer* gRenderer) {
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(gRenderer, a.x, a.y, b.x, b.y);
	SDL_RenderDrawLine(gRenderer, b.x, b.y, c.x, c.y);
	SDL_RenderDrawLine(gRenderer, c.x, c.y, a.x, a.y);

	SDL_RenderPresent(gRenderer);

}