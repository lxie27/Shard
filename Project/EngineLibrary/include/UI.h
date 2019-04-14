#ifndef UI_H
#define UI_H
#include "LTexture.h"
#include "GameConstants.h"
#include "GameStatus.h"
#include "SDLProgram.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

class UI {

public:

	/**
	*Renders all appropriate UI elements to the screen
	based on the current GameStatus defined in the GameLogic object.	
	*/
	void render();
	/**
	Checks the GameLogic object for any changes in life or score data to update the 
	UI elements.
	*/
	void update(GameStatus status_, int FPS);
	UI();

private:
	GameStatus status;
	TTF_Font *gFont = NULL;
	LTexture gGameWonTexture;
	LTexture gLevelSelectTexture;
	LTexture gFPSTexture;
	std::string fps_str;
	std::string gameWon_str = "You beat the level! \n Press any button to return to level select.";
	std::string level_select_string = "Select Level: \n Press 1 for Intro \n Press 2 for Maze \n Press 3 for Level 3 \n Press 4 for Endgame";
	/*
	*Loads text onto a LTexture to be rendered to the screen.
	*/
	bool loadText(std::string msg, LTexture &gTextTexture, SDL_Renderer* gRenderer);

};


#endif

#pragma once
