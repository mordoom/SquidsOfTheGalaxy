/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Sprite manager
	Manages the displaying of sprites on the screen
*/

#include "SpriteManager.h"
#include "SDL_image.h"
//Sprites
#include "BulletSprite.h"
#include "EnemySprite.h"
#include "EnemyBulletSprite.h"
#include "SmartEnemySprite.h"

#include <iostream>
using namespace std;

//Singleton instance
SpriteManager* SpriteManager::_instance = NULL;

SpriteManager::SpriteManager()
{
	//Init sprite sheets
	playerSprites = IMG_Load("Images/bathysphere.png");
	enemySprites = IMG_Load("Images/rsquid.png");
	bulletSprites = IMG_Load("Images/bullets.png");
}

SpriteManager::~SpriteManager()
{
	if (_instance != NULL)
	{
		//Delete everything from the sprite list
		for (unsigned i = 0; i < sprites.size(); i++)
		{
			Sprite* sprite = sprites[i];
			delete sprite;
		}

		sprites.clear();

		//Free images
		SDL_FreeSurface(playerSprites);
		SDL_FreeSurface(enemySprites);
		SDL_FreeSurface(bulletSprites);
	
		//Free singleton
		_instance = NULL;
	}
}

//Singleton pattern
SpriteManager* SpriteManager::Instance()
{
	if (_instance == NULL)
	{
		cout << "Creating SpriteManager..." << endl;
		_instance = new SpriteManager();
	}

	return _instance;
}

SDL_Surface* SpriteManager::getSpriteSheet(SPRITETYPE spriteSheet)
{
	//Use factory pattern so we aren't loading a new image every time for sprites
	if (spriteSheet == ENEMY)
		return enemySprites;
	if (spriteSheet == PLAYERBULLET || spriteSheet == ENEMYBULLET)
		return bulletSprites;
	if (spriteSheet == PLAYER)
		return playerSprites;
	else
		return playerSprites;
}

void SpriteManager::drawSprites(SDL_Surface* screen)
{
	//Clear the screen - aqua
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 153, 217, 234 ) );

	//draw the scrolling bg
	background.draw(screen);

	//Loop through each sprite
	for (unsigned i = 0; i < sprites.size(); i++)
	{
		Sprite* sprite = sprites[i];
		
		//Update the sprites position
		sprite->move();

		//Collision check here
		for (unsigned j = i+1; j < sprites.size(); j++)
		{	
			//test sprite[j] against sprite[i];
			if (collisionTest(sprites[i], sprites[j]) == HIT)
			{
				sprites[i]->shot();
				sprites[j]->shot();
			}
		}
			//if the sprite isn't dead, draw it
			if (sprite->getState() != DEAD)
				SDL_BlitSurface( getSpriteSheet(sprite->type()), sprite->getFrame(), screen, sprite->getOffsets() );
			else
			{
				sprites.erase(sprites.begin()+i);
				delete sprite;
			}
	}
}

COLLISIONTYPE SpriteManager::collisionTest(Sprite* spriteA, Sprite* spriteB)
{
	//Check if sprites have a collision type before testing
	if (spriteA->getState() != ALIVE || spriteB->getState() != ALIVE)
		return NONE;

	if (spriteA->type() == ENEMY && spriteB->type() == ENEMY)
		return NONE;

	if (spriteA->type() == PLAYER && spriteB->type() == PLAYERBULLET)
		return NONE;

	if (spriteA->type() == PLAYERBULLET && spriteB->type() == PLAYERBULLET)
		return NONE;

	//Avoidable temporaries?
	SDL_Rect A = *spriteA->getOffsets();
	SDL_Rect B = *spriteB->getOffsets();

    if ((A.y + A.h) <= B.y) return NONE;
    if (A.y >= (B.y + B.h)) return NONE;
	if ((A.x + A.w) <= B.x) return NONE;
	if (A.x >= (B.x + B.w)) return NONE;

	//If it is the player hitting a powerup
	if (spriteA->type() == PLAYER && spriteB->type() == POWERUP)
		return PICKUP;
	
	//Anything other than a powerup
	return HIT;
}

PlayerSprite* SpriteManager::newPlayer()
{
	//Create a new player sprite
	PlayerSprite* player = new PlayerSprite();
	
	//Save it to the manager
	addSprite(player);

	return player;
}

//Factory creation of sprites
void SpriteManager::newBullet(SDL_Rect* offset)
{
	addSprite(new BulletSprite(offset));
}

void SpriteManager::newEnemyBullet(SDL_Rect* offset)
{
	addSprite(new EnemyBulletSprite(offset));
}

void SpriteManager::newEnemy()
{
	addSprite(new EnemySprite());
}

void SpriteManager::newSmartEnemy()
{
	addSprite(new SmartEnemySprite());
}

void SpriteManager::addSprite(Sprite* sprite)
{
	sprites.push_back(sprite);
}