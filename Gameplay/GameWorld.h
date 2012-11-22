/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game World
	Holds the game world
*/

#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_
#include "SpriteManager.h"
#include "InputManager.h"
#include "PlayerSprite.h"
#include "SDL_ttf.h"
#include "Timer.h"

class GameWorld
{
private:
	SpriteManager* spriteManager;
	InputManager inputManager;
	PlayerSprite* player;
	bool quit;
	bool paused;
	bool smartEnemies;
	bool gameOverScreen;
	SDL_Surface* background;
	SDL_Surface* health;
	int score;
	
	//Display the score
	TTF_Font* font;
	SDL_Surface* scoreDisplay;
	SDL_Rect scoreOffset;

	//Timing
	Timer fps;
	unsigned enemyCounter;
	unsigned enemyFreq;

	//Singleton
	static GameWorld* _instance;
protected:
	GameWorld();
public:
	static GameWorld* Instance();
	~GameWorld();
	void draw(SDL_Surface* screen);
	void handleInput(SDL_Event* event);
	void update();
	void increaseScore(int n);
	void pause();
	void unpause();
	void gameOver();
	bool isPlaying();
	void activateSmartEnemies();
};
#endif /* GAMEWORLD_H_ */