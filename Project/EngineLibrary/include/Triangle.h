#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
/*! \file
*/
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

#include "Shape.h"
#include "Point.h"

/*----Class */
class Triangle : public Shape
{
public:
	Point a, b, c;
	AABB bb;

	/*Constructors*/
	~Triangle();
	Triangle(Point a, Point b, Point c);
	
	void update();

	/*Getters*/
	double getArea();
	double getPerimeter();
	AABB getBB();

	/*Setter*/
	void setBB();

	/*Renderer*/
	void render(SDL_Renderer* gRenderer);
};

#endif