#pragma once
#ifndef	SHAPE_H
#define SHAPE_H


#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

#include "Vector2.h"
#include "AABB.h"

/* ---- Class */
class Shape {
public:
	virtual ~Shape()=0;

	virtual void update() = 0;

	/* Forces */
	virtual Vector2 getForce();
	virtual void setForce(Vector2& f);
	virtual void addForce(Vector2& f);

	/* Getters */
	virtual double getArea()=0;	
	virtual double getPerimeter()=0;
	virtual AABB getBB()=0;

	/* Setter */
	virtual void setBB() = 0;
	/* Renderer */
	virtual void render(SDL_Renderer* gRenderer) = 0;

	/* Force*/
	Vector2 force;

};


#endif
