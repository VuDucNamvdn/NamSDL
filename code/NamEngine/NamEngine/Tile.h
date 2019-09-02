#pragma once
#include "LTexture.h"
class Tile
{
public:
	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	void render(SDL_Rect& camera,SDL_Renderer* ren, SDL_Rect gTileClips[12]);

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();

	//Box collision detector
	bool checkCollision(SDL_Rect a, SDL_Rect b);
private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;
};

