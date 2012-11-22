/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Sprite class
	Defines the game sprites for the sprite manager
*/

#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDL.h"
#include "SotG.h"
class Sprite
{
public: 
	Sprite();
	virtual SDL_Rect* getOffsets() = 0;
	virtual SDL_Rect* getFrame() = 0;
	virtual SPRITESTATE getState() = 0;
	virtual void move() = 0;
	virtual SPRITETYPE type() = 0;
	virtual void shot() = 0;
};
#endif /*SPRITE_H_*/