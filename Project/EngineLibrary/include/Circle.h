#ifndef CIRCLE_H
#define CIRCLE_H

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

#include "Shape.h"
#include "Point.h"

/*---- Class*/
class Circle : public Shape
{
public:
	Point center;
	double radius;
	AABB bb;

	/*----Constructors*/
	~Circle();
	Circle(Point cen, double rad);

	void update();

	/*----Getters*/
	double getArea();
	double getPerimeter();
	AABB getBB();

	/*----Setter*/
	void setBB();

	/*----Renderer*/
	void render(SDL_Renderer* gRenderer);
};

#endif
