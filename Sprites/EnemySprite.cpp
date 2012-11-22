/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Radioactive Squid sprite
*/
#include "SotG.h"
#include "EnemySprite.h"
#include "SpriteManager.h"
#include "GameWorld.h"
#include "AttackStrategy.h"

EnemySprite::EnemySprite()
{
	HP = ENEMYHP;
	state = ALIVE;
	
	//Strategy
	currentStrategy = (Strategy*)0;
	currentStrategy = new AttackStrategy();

	//Set frame durations for the sprite
	unsigned durations[5] = {10,10,10,10,20};
	animation = new Animation(5, durations, false);

	//Clip range for the first image
    clip[0].x = 0;
	clip[0].w = ENEMYSIZE;
	clip[0].h = ENEMYSIZE;
	clip[0].y = 0;

	//Set offset
	offset.x = WINWIDTH;

	//Randomise y co-ordinates when spawing a new enemy
	posy = (WINHEIGHT-(2*ENEMYSIZE))*(rand())/(RAND_MAX);
	offset.y = posy;
	offset.w = ENEMYSIZE;
	offset.h = ENEMYSIZE;

	xVel = currentStrategy->setXvel();
}

SDL_Rect* EnemySprite::getOffsets()
{
	return &offset;
}

void EnemySprite::move()
{
	//offscreen
	if (offset.x == 0)
		state = DEAD;

	offset.x -= xVel;
	
	if (state == ALIVE)
	{
		//Shoot
		if(currentStrategy->shoot())
		{
			SpriteManager* spriteManager = SpriteManager::Instance();
			spriteManager->newEnemyBullet(&offset);
		}
	}

	//If we have finished imploding
	if (animation->finished())
	{
		state = DEAD;
		GameWorld::Instance()->increaseScore(1000);
		delete animation;
		changeStrategy((Strategy*)0);
	}
}

SDL_Rect* EnemySprite::getFrame()
{
	if (state == ALIVE)
		return &clip[0];
	else
	{
		offset.x = posx;
		offset.y = posy;

		//enemy is dying
		animation->update();

		return &clip[animation->getCurrentFrame()];
	}
}

SPRITESTATE EnemySprite::getState()
{
	return state;
}

SPRITETYPE EnemySprite::type()
{
	return ENEMY;
}

void EnemySprite::shot()
{
	if (state == ALIVE)
		HP--;
	
	if (HP == 0 && state == ALIVE)
	{
		state = DYING;
	
		posx = offset.x;

		//set up the animation
		for (int i=1; i<5; i++)
		{
			clip[i].x = clip[i-1].x +ENEMYSIZE;
			clip[i].w = ENEMYSIZE;
			clip[i].h = ENEMYSIZE;
			clip[i].y = 0;
		}
	}
}

//Change strategies
void EnemySprite::changeStrategy(Strategy* newStrategy)
{
	//Memory management
	if (currentStrategy != (Strategy*)0)
		delete currentStrategy;

	//Update current strategy
	if (newStrategy != (Strategy*)0)
	{
		currentStrategy = newStrategy;
	}
}