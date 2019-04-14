#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
// Windows and Mac use a different path
// If you have compilation errors, change this as needed.
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <map>
#include <string>

class ResourceManager {

public:
	static ResourceManager *getInstance();

	/**
	Loads the resource specified by the resourceName. If the resource
	has already been loaded into memory it returns a pointer to the
	existing resource, loads new resource otherwise.
	*/
	SDL_Surface *loadResource(std::string resourceName);
	/**
	If the resourceName provided is not in use by any other objects
	then the resource will be unloaded from memory.
	*/
	void unloadResource(std::string resourceName);

private:
	static ResourceManager* instance;
	std::map<std::string, SDL_Surface*> resourceMap;
	std::map<std::string, int> resourceCount;
	ResourceManager();

};




#endif
