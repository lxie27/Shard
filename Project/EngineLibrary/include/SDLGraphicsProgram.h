#ifndef SDLGRAPHICSPROGRAM_H
#define SDLGRAPHICSPROGRAM_H

// ==================== Libraries ==================
// Depending on the operating system we use
// The paths to SDL are actually different.
// The #define statement should be passed in
// when compiling using the -D argument.
// This gives an example of how a programmer
// may support multiple platforms with different
// dependencies.
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>
#include "Triangle.h"
#include "Quad.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Rectangle;

class SDLGraphicsProgram {
public:
	// Constructor
	SDLGraphicsProgram(int w, int h);
	// Destructor
	~SDLGraphicsProgram();
	// Setup OpenGL
	bool initGL();
	// Clears the screen
	void clear();
	// It swaps out the previvous frame in a double-buffering system
	void flip();
	//delays SDL for next loop
	void delay(int milliseconds);
	// Per frame update
	void update();
	// Renders shapes to the screen
	void render();
	// loop that runs forever
	void loop();
	// Get Pointer to Window
	SDL_Window* getSDLWindow();
	// Helper Function to Query OpenGL information.
	void getOpenGLVersionInfo();

	void DrawRectangle(Quad rect);

private:
	// Screen dimension constants
	int screenHeight;
	int screenWidth;
	// The window we'll be rendering to
	SDL_Window* gWindow;
	// OpenGL context
	SDL_GLContext gContext;
	// Renderer
	SDL_Renderer* gRenderer;
};

#endif