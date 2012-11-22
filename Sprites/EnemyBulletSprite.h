/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Enemy ink bullet sprite
*/

#ifndef ENEMYBULLETSPRITE_H_
#define ENEMYBULLETSPRITE_H_
#include "Sprite.h"
#include "Animation.h"

class EnemyBulletSprite :	public Sprite
{
private:
	SDL_Rect clip[4];
	SDL_Rect offset;
	int xVel;
	SPRITESTATE state;
	Animation* animation;
public:
	EnemyBulletSprite(SDL_Rect* offsetRect);
	~EnemyBulletSprite();
	SDL_Rect* getOffsets();
	SDL_Rect* getFrame();
	SPRITESTATE getState();
	void move();
	SPRITETYPE type();
	void shot();
};

#endif /*ENEMYBULLETSPRITE_H_*/

