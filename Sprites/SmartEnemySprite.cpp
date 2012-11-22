/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Radioactive Squid sprite
*/
#include "SotG.h"
#include "SmartEnemySprite.h"
#include "SpriteManager.h"
#include "GameWorld.h"
#include "CampStrategy.h"
#include "KamikazeStrategy.h"

SmartEnemySprite::SmartEnemySprite()
{
	HP = SMARTENEMYHP;
	state = ALIVE;

	//Adopt a strategy
	currentStrategy = (Strategy*)0;
	changeStrategy(new CampStrategy());

	//Set frame durations for the sprite
	unsigned durations[5] = {10,10,10,10,20};
	animation = new Animation(5, durations, false);

	//Clip range for the first image
    clip[0].x = 0;
	clip[0].w = ENEMYSIZE;
	clip[0].h = ENEMYSIZE;
	clip[0].y = ENEMYSIZE;

	//Set offset so the enemy is on the screen
	offset.x = WINWIDTH-ENEMYSIZE;
	//Randomise y co-ordinates when spawing a new enemy
	posy = (WINHEIGHT-(2*ENEMYSIZE))*(rand())/(RAND_MAX);
	offset.y = posy;
	offset.w = ENEMYSIZE;
	offset.h = ENEMYSIZE;
}

SDL_Rect* SmartEnemySprite::getOffsets()
{
	return &offset;
}

void SmartEnemySprite::move()
{
	//offscreen
	if (offset.x == 0)
	{
		state = DEAD;
		GameWorld::Instance()->activateSmartEnemies();
	}

	offset.x -= xVel;
	
	if (state == ALIVE)
	{
		//Consult strategy
		if(currentStrategy->shoot())
		{
			SpriteManager* spriteManager = SpriteManager::Instance();
			spriteManager->newEnemyBullet(&offset);
		}
	}
	
	//If we have finished imploding
	if (animation->getCurrentFrame()==5)
	{
		state = DEAD;
		delete animation;
		//This will ensure the strategy memory is deallocated	
		changeStrategy((Strategy*)0);

		GameWorld::Instance()->activateSmartEnemies();
		GameWorld::Instance()->increaseScore(2500);
	}
}

SDL_Rect* SmartEnemySprite::getFrame()
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

SPRITESTATE SmartEnemySprite::getState()
{
	return state;
}

SPRITETYPE SmartEnemySprite::type()
{
	return ENEMY;
}

void SmartEnemySprite::shot()
{
	if (state == ALIVE)
	{
		HP--;

		if (HP == 3)
			changeStrategy(new KamikazeStrategy());
	}
	
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
			clip[i].y = ENEMYSIZE;
			
		}
	}
}

//Change strategies
void SmartEnemySprite::changeStrategy(Strategy* newStrategy)
{
	//Memory management
	if (currentStrategy != (Strategy*)0)
		delete currentStrategy;

	//Update current strategy
	if (newStrategy != (Strategy*)0)
	{
		currentStrategy = newStrategy;
		xVel = currentStrategy->setXvel();
	}
}