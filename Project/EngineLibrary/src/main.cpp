#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else  
#include <SDL.h>
#endif

/*! \file
main.cpp: The compiler for the shard module.
*/

#include <glad/glad.h>
#include "SDLGraphicsProgram.h"

#include "Shape.h"
#include "Point.h"
#include "Quad.h"
#include "Triangle.h"
#include "Circle.h"
#include "Physics.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

/*!
\brief The constructor.
\param w The screen width of the SDL window.
\param h The screen height of the SDL window.
\return The SDLGraphicsProgram instance.
*/
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h) :screenWidth(w), screenHeight(h) {
	// Initialization flag
	bool success = true;
	// String to hold any errors that occur.
	stringstream errorStream;
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

/*!
\brief The deconstuctor.
*/
SDLGraphicsProgram::~SDLGraphicsProgram() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	// Point gWindow to NULL to ensure it points to nothing.
	gWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}


/*!
\brief Initializer flag for SDLGraphicsProgram.
*/
bool SDLGraphicsProgram::initGL() {
	//Success flag
	bool success = true;

	return success;
}


/*!
\brief Clears the screen.
*/
void SDLGraphicsProgram::clear() {
	// Nothing yet!
	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x4, 0xFF);
	SDL_RenderClear(gRenderer);
}

/*
\brief Re-renders the screen.
*/
void SDLGraphicsProgram::flip() {
	// Nothing yet!
	SDL_RenderPresent(gRenderer);
}

/*!
\brief Delays the screen.
\param milliseconds The ms delay for each loop.
*/
void SDLGraphicsProgram::delay(int milliseconds) {
	SDL_Delay(milliseconds);
}

/*!
\brief Updates the logic of the physics engine.
*/
void SDLGraphicsProgram::update() {
	pEngine.update();
	renderShapes();
	cout << "updating" << endl;
}

/*!
\brief Draws all the shapes in the physics engine. Delegates drawing to the shape type.
*/
void SDLGraphicsProgram::renderShapes() {
	vector<Shape*> shapes = pEngine.getShapes();

	for (auto s : shapes)
	{
		s->render(gRenderer);
		/*
		//delegate rendering to the concrete type of Shape	
		cout << "Attempting to render Shape" << endl;
		if (!dynamic_cast <Quad*>(s)->render(gRenderer)) {
			SDL_RenderPresent(gRenderer);
		}
		else if (!dynamic_cast <Triangle*>(s)->render(gRenderer)) {
			SDL_RenderPresent(gRenderer);
		}
		else if (!dynamic_cast <Circle*>(s)->render(gRenderer)) {
			SDL_RenderPresent(gRenderer);
		}*/
	}
}

/*
\brief Main loop for SDLGraphicsProgram.
*/
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
		
		update();
		//Update screen of our specified window
		SDL_GL_SwapWindow(getSDLWindow());
	}

	//Disable text input
	SDL_StopTextInput();
}


/*!
\brief Gets the SDL_Window.
\returns The SDL_Window of this SDLGraphicsProgram.
*/
SDL_Window* SDLGraphicsProgram::getSDLWindow() {
	return gWindow;
}

/*!
\brief Adds a shape to the physics engine.
*/
void SDLGraphicsProgram::addShape(Shape* q) {
	pEngine.addShape(q);
}

/*!
\brief Resets the physics engine
\param p Physics engine to be set to
*/
void SDLGraphicsProgram::setPhysics(Physics& p) {
	pEngine = p;
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

/*!
\brief Binds functions to shard.pyd
\param m The module given to Python
*/
PYBIND11_MODULE(shard, m){
	py::class_<Point>(m, "Point")
		.def(py::init<double, double>(), py::arg("x"), py::arg("y"));
	/*py::class_ < Shape, PyShape> shape(m, "Shape");
	shape
		.def(py::init<>());
	*/
	py::class_<Quad>(m, "Quad")
		.def(py::init<Point, Point, Point, Point>(), py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
	py::class_<Triangle>(m, "Triangle")
		.def(py::init<Point, Point, Point>(), py::arg("a"), py::arg("b"), py::arg("c"));
	py::class_<Physics>(m, "Physics")
		.def(py::init<>())
		.def("pAddShape", &Physics::addShape);
	py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
		.def(py::init<int, int>(), py::arg("w"), py::arg("h"))   // our constructor
		.def("clear", &SDLGraphicsProgram::clear) // Expose member methods
		.def("delay", &SDLGraphicsProgram::delay)
		.def("flip", &SDLGraphicsProgram::flip)
		.def("loop", &SDLGraphicsProgram::loop)
		.def("update", &SDLGraphicsProgram::update)
		.def("addShape", &SDLGraphicsProgram::addShape)
		.def("setPhysics", &SDLGraphicsProgram::setPhysics)
		.def("render", &SDLGraphicsProgram::renderShapes);
}