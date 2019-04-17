#ifndef SDLGRAPHICSPROGRAM_H
#define SDLGRAPHICSPROGRAM_H

/*
SDLGraphicsProgram.h: SDL program
*/
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>
#include "Physics.h"
#include "Shape.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

/* ---- Classes */
class SDLGraphicsProgram {
public:
	SDLGraphicsProgram(int w, int h);
	~SDLGraphicsProgram();
	// Setup OpenGL
	bool initGL();
	void clear();
	void flip();
	void delay(int milliseconds);
	void update();
	void renderShapes();
	void loop();
	SDL_Window* getSDLWindow();
	void getOpenGLVersionInfo();

	void addShape(Shape* q);

	void setPhysics(Physics& p);

	Physics pEngine;

private:
	int screenHeight;
	int screenWidth;
	SDL_Window* gWindow;
	SDL_GLContext gContext;
	SDL_Renderer* gRenderer;
};

#endif