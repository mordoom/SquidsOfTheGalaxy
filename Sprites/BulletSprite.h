/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Pulse bullet sprite
*/

#ifndef BULLETSPRITE_H_
#define BULLETSPRITE_H_
#include "Sprite.h"
#include "Animation.h"

class BulletSprite :	public Sprite
{
private:
	SDL_Rect clip[4];
	SDL_Rect offset;
	int xVel;
	SPRITESTATE state;
	Animation* animation;
public:
	BulletSprite(SDL_Rect* offsetRect);
	~BulletSprite();
	SDL_Rect* getOffsets();
	SDL_Rect* getFrame();
	SPRITESTATE getState();
	void move();
	SPRITETYPE type();
	void shot();
};

#endif /*BULLETSPRITE_H_*/

