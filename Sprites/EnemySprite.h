/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Radioactive Squid sprite
*/

#ifndef ENEMYSPRITE_H_
#define ENEMYSPRITE_H_
#include "Sprite.h"
#include "Animation.h"
#include "Strategy.h"

class EnemySprite :	public Sprite
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
	EnemySprite();
	~EnemySprite();
	SDL_Rect* getOffsets();
	SDL_Rect* getFrame();
	SPRITESTATE getState();
	SPRITETYPE type();
	void move();
	void shot();
	void changeStrategy(Strategy* newStrategy);
};

#endif /*ENEMYSPRITE_H_*/

