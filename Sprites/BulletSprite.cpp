/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Pulse bullet sprite
*/
#include "SotG.h"
#include "BulletSprite.h"
BulletSprite::BulletSprite(SDL_Rect* offsetRect)
{
	state = ALIVE;

	//Set frame durations for the sprite
	unsigned durations[4] = {4,4,4,4};
	animation = new Animation(4, durations, false);

	//Clip range for the first image
    clip[0].x = 0;
	clip[0].w = BULLETSIZE;
	clip[0].h = BULLETSIZE;
	clip[0].y = 0;

	//Set offset
	offset.x = offsetRect->x+BULLETSIZE;
	offset.y = offsetRect->y+BULLETSIZE;
	offset.w = BULLETSIZE;
	offset.h = BULLETSIZE;

	//Set velocity
	xVel = BULLETSPEED;
}

SDL_Rect* BulletSprite::getOffsets()
{
	return &offset;
}

void BulletSprite::move()
{
	if (state != DYING)
		offset.x += xVel;

	//offscreen
	if (offset.x > WINWIDTH)
		state = DEAD;

	//If we have finished exploding
	if (animation->finished())
	{
		state = DEAD;
		delete animation;
	}
}

SDL_Rect* BulletSprite::getFrame()
{
	if (state != DYING)
		return &clip[0];
	else
	{
		//bullet has collided with something
		animation->update();
		return &clip[animation->getCurrentFrame()];
	}
}

SPRITESTATE BulletSprite::getState()
{
	return state;
}

SPRITETYPE BulletSprite::type()
{
	return PLAYERBULLET;
}

void BulletSprite::shot()
{
	if (state != DYING)
	{
		state = DYING;

		//set up the animation
		for (int i=1; i<4; i++)
		{
			clip[i].x = clip[i-1].x +BULLETSIZE;
			clip[i].w = BULLETSIZE;
			clip[i].h = BULLETSIZE;
			clip[i].y = 0;
		}
	}
}