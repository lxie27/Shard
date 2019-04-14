#include "TinyMath.h"

#include <stdio.h>
#include <string>
#include <iostream>


// Frame Capping Vars
unsigned int fpsRendered = 0;
int activeFPS = 0;
//unsigned int lastTime = SDL_GetTicks();
const int DESIRED_FRAME_RATE = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;


void update() {
	//GameControl::getInstance()->update(activeFPS);
}


void render() {
	Clear screen

	SDL_Renderer* gRenderer = SDLProgram::getInstance()->getRenderer();

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	GameControl::getInstance()->render();

	//Update screen
	SDL_RenderPresent(gRenderer);
	
}



int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!SDLProgram::getInstance()->started())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;
		render();

		//While application is running
		while (!quit)
		{
			
			unsigned int currentTime = SDL_GetTicks(); // Get frame start time
			int elapsedTime = currentTime - lastTime;  // Time since last counted second
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{

			}

			update();
			render();

			// FPS Counter
			fpsRendered++; // Count frame
			// If one second has past, print the FPS and reset
			if (elapsedTime >= 1000) {
				//std::cout << fpsRendered << std::endl;
				activeFPS = fpsRendered;
				lastTime = currentTime;
				fpsRendered = 0;
			}

			// If frame finished early delay
			if (SDL_GetTicks() - currentTime < SCREEN_TICKS_PER_FRAME) {
				SDL_Delay(SCREEN_TICKS_PER_FRAME - (SDL_GetTicks() - currentTime));
			}

		}
		
	}

	//Free resources and close SDL
	//SDLProgram::getInstance()->close();

	return 0;
}

#include <pybind11/pybind11.h>


namespace py = pybind11;

// g++ -std=c++14 -shared -fPIC -static-libgcc -static-libstdc++ -I./include/ -I./pybind11/include/ `python3.6 -m pybind11 --includes` *.cpp -o mygameengine.pyd `python3.6-config --ldflags` -lmingw32 -mwindows -L libwinpthread-1.dll


PYBIND11_MODULE(shard, m) {
	m.def("addVector", &addVector, "Add values of a vector's x y and z together");
	m.def("add", &add, "Add two ints");
	py::class_<Vector3D>(m, "Vector3D")
		.def(py::init<float, float, float>(), py::arg("x"), py::arg("y"), py::arg("z"));
}