#pragma once
#include "Tile.h"
class Dot
{
public:
	//A circle stucture
	struct Circle
	{
		int x, y;
		int r;
	};
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Dot(int x, int y);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot and checks collision
	void move(Tile *tiles[]);
	//Shows the dot on the screen
	void render(SDL_Renderer* ren, SDL_Rect& camera);
	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);
	//Position accessors
	int getPosX();
	int getPosY();

	//Circle/Circle collision detector
	bool checkCollision(Circle& a, Circle& b);

	//Circle/Box collision detector
	bool checkCollision(Circle& a, SDL_Rect& b);
	//Box collision detector
	bool checkCollision(SDL_Rect a, SDL_Rect b);
	//Checks collision box against set of tiles
	bool touchesWall(SDL_Rect box, Tile* tiles[]);
	//Calculates distance squared between two points
	double distanceSquared(int x1, int y1, int x2, int y2);
	Circle& getCollider()
	{
		return mCollider;
	}
private:

	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;
	LTexture*gDotTexture;
	//Dot's collision circle
	Circle mCollider;
	SDL_Rect mBox;
	//Moves the collision boxes relative to the dot's offset
	void shiftColliders();
};

