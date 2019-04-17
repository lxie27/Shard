#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif
/*! \file
Quad.cpp: the Quad (rectangle) shape.
*/
#include <iostream>
#include "Quad.h"
#include "Point.h"

using namespace std;

/*!
\brief The deconstructor.
*/
Quad::~Quad() {}

/*!
\brief The constructor
\param a The topleft corner of the Quad
\param b The topright corner of the Quad
\param c The bottomleft corner of the Quad
\param d The bottomright corner of the Quad
\returns Quad instance
*/
Quad::Quad(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d)	
{
	Vector2 v = Vector2(0.0, 0.0);
	setForce(v);
}

/*!
\brief Updates the Quad's Points based on its current force.
*/
void Quad::update() {
	a.x = a.x + force.x;
	b.x = b.x + force.x;
	c.x = c.x + force.x;
	d.x = d.x + force.x;

	a.y = a.y + force.y;
	b.y = b.y + force.y;
	c.y = c.y + force.y;
	d.y = d.y + force.y;
}

/*!
\brief Gets the area of the Quad.
\returns Returns w * h = area.
*/
double Quad::getArea() {
	return (a.y - c.y) * (b.x - a.x);
}

/*!
\brief Gets the perimeter of the Quad.
\returns Returns 2w + 2h = perimeter.
*/
double Quad::getPerimeter() {
	return (b.x - a.x) + (d.y - b.y) + (d.x - c.x) + (c.y - a.y);
}

/*!
\brief Gets the AABB of the Quad.
\returns Returns the AABB of the Quad.
*/
AABB Quad::getBB() {
	return bb;
}

/*!
\brief Sets the AABB of the Quad based on its current coordinates.
*/
void Quad::setBB() {
	bb = AABB(a.x, a.y, d.x, d.y);
}

/*!
\brief Renders the Quad, delegated by Shape inheritance.
\param gRenderer The SDL_Renderer of SDLGraphicsProgram.
*/
void Quad::render(SDL_Renderer* gRenderer) {
	Point center = Point((b.x - a.x) / 2, (b.y - d.y) / 2);
	int width = b.x - a.x;
	int height = b.y - d.y;

	SDL_Rect fillRect = { a.x + center.x, a.y - center.y, width, height };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &fillRect);

	SDL_RenderPresent(gRenderer);

}

/*!
\brief Sets the force of the Quad.
\param f The force to be set to.
*/
void Quad::setForce(Vector2& f) {
	cout << "Quad setting force" << endl;
	force = f;
}

/*!
\brief Adds to the force of the Quad.
\param f The force to be added.
*/
void Quad::addForce(Vector2& f) {
	cout << "Quad adding force" << endl;
	Vector2 v = Vector2((f.x + force.x), (f.y + force.y));
	setForce(v);
}