/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game World
	Holds the game world

	-I could improve the HUD system by refactoring it
	into it's own class, reducing it's coupling with the
	GameWorld class

	-At the moment, for demonstration purposes, there are
	some methods for getting 'smartEnemies' that use strategy
	pattern on the screen. If further work would be done on
	this project I would like to refactor the entire enemy spawning
	algorithm into an 'EnemyManager' class that decides when they should
	spawn.
*/

#include "GameWorld.h"
#include "SotG.h"
#include "SDL_image.h"
#include <stdlib.h>

//Singleton instance
GameWorld* GameWorld::_instance = NULL;

GameWorld::GameWorld()
{
	quit = false;
	paused = false;
	gameOverScreen = false;
	smartEnemies = false;
	enemyCounter = SDL_GetTicks();
	enemyFreq = ENEMYFREQ;
	fps.start();

	//Score
	score = 0;
	font = TTF_OpenFont( "emulogic.ttf", 20 );
	scoreOffset.x = WINWIDTH-150;
	scoreOffset.y = 50;

	//Set up the sprite Manager
	spriteManager = SpriteManager::Instance();

	//Create the player and give it a sprite from the manager
	player = spriteManager->newPlayer();

	//Test enemy
	spriteManager->newSmartEnemy();

	//Health
	health = IMG_Load("Images/health.png");

	//Initialize SDL_ttf
    TTF_Init();   
}

GameWorld::~GameWorld()
{
	if (_instance != NULL)
	{
		delete spriteManager;
		SDL_FreeSurface(health);
		TTF_CloseFont(font);
		_instance = NULL;
	}
}

//Singleton pattern
GameWorld* GameWorld::Instance()
{
	if (_instance == NULL)
	{
		printf("Creating game world...");
		_instance = new GameWorld();
	}

	return _instance;
}

void GameWorld::draw(SDL_Surface* screen)
{
	//Pause
	if (paused)
		return;
	
	//Regulate the frame rate
	fps.update();

	//Draw sprites
	spriteManager->drawSprites(screen);

	//Draw player health bar
	SDL_Rect offset;
	offset.x = 0;
	offset.y = 50;

	for (int i = 0; i< player->getHP(); i++)
	{
		offset.x += 32;
		SDL_BlitSurface( health, NULL, screen,  &offset);
	}
	
	//Show the score
	SDL_Color yellow = {255, 255, 0};
	char buf[10];
	itoa(score, buf, 10);
	scoreDisplay = 	TTF_RenderText_Solid( font, buf, yellow );
	SDL_BlitSurface( scoreDisplay, NULL, screen,  &scoreOffset);
}

void GameWorld::handleInput(SDL_Event* event)
{
	//Pause
	if (paused || gameOverScreen)
		return;

	int key = event->key.keysym.sym;
	if (event->key.type ==SDL_KEYDOWN)
	{
		//Check input
		switch( inputManager.handleInput(key) )
		{
			default: break;
			case 'u': player->moveYaxis(-PLAYERSPEED); break;
			case 'd': player->moveYaxis(PLAYERSPEED); break;
			case 'l': player->moveXaxis(-PLAYERSPEED); break;
			case 'r': player->moveXaxis(PLAYERSPEED); break;
			case 'f': spriteManager->newBullet(player->getOffsets());break;
		}
	}
	else if (event->key.type ==SDL_KEYUP)
	{
		//Check input
		switch( inputManager.handleInput(key) )
		{
			default: break;
			case 'u': player->moveYaxis(0); break;
			case 'd': player->moveYaxis(0); break;
			case 'l': player->moveXaxis(0); break;
			case 'r': player->moveXaxis(0); break;
			//case 'f': break;
		}
	}
}

void GameWorld::update()
{
	//Pause
	if (paused)
		return;

	//Tell the sprite manager to spawn more enemies every so often
	//Could use an enemy manager here, so the algorithm to spawn enemies
	//is seperate from the GameWorld class.
	if( SDL_GetTicks() < (enemyCounter+enemyFreq) )
		return;
	
	//Increase spawning frequency until limit
	if (enemyFreq > ENEMYSPAWNMAX)
		enemyFreq-=ENEMYFREQINC;

	enemyCounter = SDL_GetTicks();

	//Spawn
	spriteManager->newEnemy();

	if (smartEnemies)
	{
		spriteManager->newSmartEnemy();
		smartEnemies = false;
	}
}

//Pause the game
void GameWorld::pause()	{paused = true;}
void GameWorld::unpause()	{paused = false;}

//Display game over screen
void GameWorld::gameOver() {gameOverScreen = true;}

//return whether or not the game is still playing
bool GameWorld::isPlaying() {return !gameOverScreen;}

//Increase score
void GameWorld::increaseScore(int n) {score += n;}

//Activate smart enemies
void GameWorld::activateSmartEnemies()
{
	smartEnemies = true;
}