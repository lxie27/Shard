#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>
#include "SDLGraphicsProgram.h"

#include "Point.h"
#include "Quad.h"
#include "Triangle.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h) :screenWidth(w), screenHeight(h) {
	// Initialization flag
	bool success = true;
	// String to hold any errors that occur.
	std::stringstream errorStream;
	// The window we'll be rendering to
	gWindow = NULL;
	// Render flag

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else {
		//Create window
		gWindow = SDL_CreateWindow("Lab", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

		// Check if Window did not create.
		if (gWindow == NULL) {
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		// Check if Renderer did not create.
		if (gRenderer == NULL) {
			errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}
	}



	// If initialization did not work, then print out a list of errors in the constructor.
	if (!success) {
		errorStream << "SDLGraphicsProgram::SDLGraphicsProgram - Failed to initialize!\n";
		std::string errors = errorStream.str();
		SDL_Log("%s\n", errors.c_str());
	}
	else {
		SDL_Log("SDLGraphicsProgram::SDLGraphicsProgram - No SDL, GLAD, or OpenGL, errors detected during initialization\n\n");
	}

}


// Proper shutdown of SDL and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	// Point gWindow to NULL to ensure it points to nothing.
	gWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}


// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::initGL() {
	//Success flag
	bool success = true;

	return success;
}


// clear
// Clears the screen
void SDLGraphicsProgram::clear() {
	// Nothing yet!
	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x4, 0xFF);
	SDL_RenderClear(gRenderer);
}
// Flip
// The flip function gets called once per loop
// It swaps out the previvous frame in a double-buffering system
void SDLGraphicsProgram::flip() {
	// Nothing yet!
	SDL_RenderPresent(gRenderer);
}


void SDLGraphicsProgram::delay(int milliseconds) {
	SDL_Delay(milliseconds);
}


//Loops forever!
void SDLGraphicsProgram::loop() {
	// Main loop flag
	// If this is quit = 'true' then the program terminates.
	bool quit = false;
	// Event handler that handles various events in SDL
	// that are related to input and output
	SDL_Event e;
	// Enable text input
	SDL_StartTextInput();
	// While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			// User posts an event to quit
			// An example is hitting the "x" in the corner of the window.
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		} // End SDL_PollEvent loop.

		//Update screen of our specified window
		SDL_GL_SwapWindow(getSDLWindow());
	}

	//Disable text input
	SDL_StopTextInput();
}


// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow() {
	return gWindow;
}

// Okay, render our rectangles!
void SDLGraphicsProgram::DrawRectangle(Quad& rect) {
	//Point center = Point((rect.b.x - rect.a.x) / 2, (rect.b.y - rect.d.y) / 2);
	int width = rect.b.x - rect.a.x;
	int height = rect.b.y - rect.d.y;

	SDL_Rect fillRect = { rect.a.x, rect.a.y, width, height };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &fillRect);
}

#include <pybind11/pybind11.h>

namespace py = pybind11;

// Creates a macro function that will be called shard
PYBIND11_MODULE(shard, m){
	py::class_<Point>(m, "Point")
		.def(py::init<double, double>(), py::arg("x"), py::arg("y"));
	py::class_<Quad>(m, "Quad")
		.def(py::init<Point, Point, Point, Point>(), py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
	py::class_<Triangle>(m, "Triangle")
		.def(py::init<Point, Point, Point>(), py::arg("a"), py::arg("b"), py::arg("c"));
	py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
		.def(py::init<int, int>(), py::arg("w"), py::arg("h"))   // our constructor
		.def("clear", &SDLGraphicsProgram::clear) // Expose member methods
		.def("delay", &SDLGraphicsProgram::delay)
		.def("flip", &SDLGraphicsProgram::flip)
		.def("loop", &SDLGraphicsProgram::loop)
		.def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle);
}