
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H


#include "Tile.h"
#include "Player.h"
#include "TinyMath.h"
#include "LevelLoader.h"
#include "GameConstants.h"
#include "Enemy.h"
#include "GameControl.h"


/**
Handles collision between the player and the world.
*/
class CollisionManager {
public:
	/**
	Checks the collision of the player against an object in the world defined by the given
	x,y,width and height
	*/
    bool checkPlayerCollision(Player &p, int brx, int bry, int brw, int brh, TileType type);

	/**
	Iterates through the objects in the world that the player can collide with
	and calls checkPlayerCollission against each one.
	*/
	void checkPlayerLevelCollision(Player &p, Enemy *enemies, int enemyCount);

	/**
	Handles the appropriate outcome for what happens when the player collides with a static tile.
	*/
	void handlePlayerLevelCollide(Player &p, int left, int right, int top, int bot);


private:

};


#endif 