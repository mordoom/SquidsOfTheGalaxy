/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Sprite manager
	Manages the displaying of sprites on the screen
*/

#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_
#include "Sprite.h"
#include "SDL.h"
#include <vector>
#include <map>
#include "PlayerSprite.h"
#include "SotG.h"
#include "Scrolling.h"
using namespace std;
class SpriteManager
{
protected:
	SpriteManager();
private:
	static SpriteManager* _instance;
	SDL_Surface* playerSprites;
	SDL_Surface* enemySprites;
	SDL_Surface* bulletSprites;
	Scrolling background;
	vector<Sprite*> sprites;
public: 
	static SpriteManager* Instance();
	~SpriteManager();
	SDL_Surface* getSpriteSheet(SPRITETYPE spriteSheet);
	void drawSprites(SDL_Surface* screen);
	COLLISIONTYPE collisionTest(Sprite* spriteA, Sprite* spriteB);
	void addSprite(Sprite* sprite);
	PlayerSprite* newPlayer();
	void newBullet(SDL_Rect* offset);
	void newEnemy();
	void newEnemyBullet(SDL_Rect* offset);
	void newSmartEnemy();
};
#endif /*SPRITEMANAGER_H_*/