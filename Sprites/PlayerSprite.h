/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Player Sprite
	Sprite information for the player
*/

#ifndef PLAYERSPRITE_H_
#define PLAYERSPRITE_H_
#include "Sprite.h"
#include "Animation.h"

class PlayerSprite :	public Sprite
{
private:
	SDL_Rect clip[5];
	SDL_Rect dying[5];
	SDL_Rect moveUp[5];
	SDL_Rect offset;
	Animation* animation;
	Animation* dyingAnimation;
	int xVel;
	int yVel;
	int HP;
	PLAYERSTATE animationState;
	SPRITESTATE state;
public:
	PlayerSprite();
	~PlayerSprite();
	SDL_Rect* getOffsets();
	SDL_Rect* getFrame();
	SPRITESTATE getState();
	SPRITETYPE type();
	void shot();

	//Movement
	void move();
	void moveXaxis(int x);
	void moveYaxis(int y);

	//Health
	int getHP();
};

#endif /*MOVERIGHTSPRITE_H_*/

