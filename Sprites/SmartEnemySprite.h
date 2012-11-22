/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Poison Barb Enemy Sprite
*/

#ifndef SMARTENEMYSPRITE_H_
#define SMARTENEMYSPRITE_H_
#include "Sprite.h"
#include "Animation.h"
#include "Strategy.h"

class SmartEnemySprite :	public Sprite
{
private:
	SDL_Rect clip[5];
	SDL_Rect offset;
	int xVel;
	SPRITESTATE state;
	int HP;
	int posy;
	int posx;
	Strategy* currentStrategy;
	Animation* animation;
public:
	SmartEnemySprite();
	~SmartEnemySprite();
	SDL_Rect* getOffsets();
	SDL_Rect* getFrame();
	SPRITESTATE getState();
	SPRITETYPE type();
	void move();
	void shot();
	void changeStrategy(Strategy* newStrategy);
};

#endif /*ENEMYSPRITE_H_*/

