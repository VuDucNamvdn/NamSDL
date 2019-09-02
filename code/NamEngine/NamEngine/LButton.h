#pragma once
#include "LTexture.h"
//Mouse button sprites
enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

const int TOTAL_BUTTONS = 4;
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
class LButton
{
public:

	SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
	//Initializes internal variables
	LButton();

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	//Shows button sprite
	void render();
	LTexture* gButtonSpriteSheetTexture;
private:
	//Top left position
	SDL_Point mPosition;

	//Currently used global sprite
	LButtonSprite mCurrentSprite;

};

