/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Player Sprite
	Sprite information for the player
*/
#include "PlayerSprite.h"
#include "GameWorld.h"
PlayerSprite::PlayerSprite()
{
	HP = PLAYER_HP;
	state = ALIVE;

	animationState = IDLE;

	//Set frame durations for the sprite
	unsigned durations[5] = {4,4,4,4,4};
	animation = new Animation(5, durations, true);

	//Set width, height and y for all clips
	for (int i=0; i<5; i++)
	{
		clip[i].w = PLAYERSIZE;
		clip[i].h = PLAYERSIZE;
		clip[i].y = 0;
	}

	//Set width, height and y for all clips
	for (int i=0; i<5; i++)
	{
		moveUp[i].w = PLAYERSIZE;
		moveUp[i].h = PLAYERSIZE;
		moveUp[i].y = PLAYERSIZE;
	}


	//Clip range for the first image
    clip[0].x = 0;
	moveUp[0].x = 0;

	//Clip x ranges
	for (int i=1; i<5;i++)
	{
		clip[i].x = clip[i-1].x+PLAYERSIZE;
		moveUp[i].x = moveUp[i-1].x+PLAYERSIZE;
	}

	//Set offset
	offset.x = 200;
	offset.y = 200;
	offset.w = PLAYERSIZE;
	offset.h = PLAYERSIZE;
	
	//Set velocity
	xVel = 0;
	yVel = 0;
}

SDL_Rect* PlayerSprite::getOffsets()
{
	return &offset;
}

void PlayerSprite::move()
{
	//If the player has finished exploding, it is now a game over
	if (state == DYING && dyingAnimation->finished())
	{
		state = DEAD;
		//Memory management
		delete animation;
		delete dyingAnimation;
		GameWorld::Instance()->gameOver();
	}

	offset.x += xVel;
	offset.y += yVel;

	//Horizontal wall
	if (offset.x >= (WINWIDTH/2)-PLAYERSIZE)
		offset.x -=xVel;

	//Vertical wall
	if (offset.y >= (WINHEIGHT-PLAYERSIZE))
		offset.y -= yVel;
}

void PlayerSprite::moveXaxis(int x)
{
	if (x != 0)
		animationState = HORIZONTAL;
	else
		animationState = IDLE;
	
	xVel = x;
}
void PlayerSprite::moveYaxis(int y)
{
	if (y != 0)
		animationState = VERTICAL;
	else
		animationState = IDLE;

	yVel = y;
}

SPRITESTATE PlayerSprite::getState() {return state;}

SDL_Rect* PlayerSprite::getFrame()
{
	if (state == DYING)
	{
		//Advance the animation
		dyingAnimation->update();

		return &dying[dyingAnimation->getCurrentFrame()];
	}

	if (state == ALIVE)
	{
		if (animationState == HORIZONTAL)
		{
			//Advance the animation
			animation->update();

			return &clip[animation->getCurrentFrame()];
		}
		else if (animationState == VERTICAL)
		{
			//Advance the animation
			animation->update();

			return &moveUp[animation->getCurrentFrame()];
		}
		else if (animationState == IDLE)
			return &clip[0];
	}
}

SPRITETYPE PlayerSprite::type()
{
	return PLAYER;
}

void PlayerSprite::shot()
{
	//Take damage
	if (HP > 0)
		HP--;
	else
	{
		state = DYING;
	
		//Set up animation
		unsigned durations[5] = {10,10,10,10,20};
		dyingAnimation = new Animation(5, durations, false);
		for (int i=0;i<5;i++)
		{
			dying[i].x = i*PLAYERSIZE;
			dying[i].y = PLAYERSIZE*2;
			dying[i].w = PLAYERSIZE;
			dying[i].h = PLAYERSIZE;
		}

	}
}

int PlayerSprite::getHP()
{
	return HP;
}