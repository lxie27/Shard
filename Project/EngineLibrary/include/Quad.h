#pragma once
#ifndef QUAD_H
#define QUAD_h

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

#include "Shape.h"
#include "Point.h"
#include "Vector2.h"

/* ---- Class */
class Quad : public Shape
{
public:
	Point a, b, c, d;
	AABB bb;

	~Quad();
	//Convention: a is the TL point, b is TR point, c is BL point, d is BR point
	Quad(Point a, Point b, Point c, Point d);

	void update();

	/* ---- Getter */
	double getArea();
	double getPerimeter();
	AABB getBB();

	/* ---- Setter */
	void setBB();
	void setForce(Vector2& f);

	void addForce(Vector2& f);

	/* ---- Renderer */
	void render(SDL_Renderer* gRenderer);
};

#endif