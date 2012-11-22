/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Gameplay State
	Game state where the game is actually played
*/

#include "GameplayState.h"
#include "StateManager.h"
#include "GameOverState.h"

//Constructor
GameplayState::GameplayState()
{
	gameWorld = GameWorld::Instance();
}

GameplayState::~GameplayState(){}

void GameplayState::display(SDL_Surface* screen)
{
	//Draw the world
	gameWorld->draw(screen);
}

void GameplayState::userInput(SDL_Event* event)
{
	//Send the input to the game world if it is relevant
	if (event->key.type == SDL_KEYDOWN || event->key.type == SDL_KEYUP)
		gameWorld->handleInput(event);
}

void GameplayState::update(StateManager* gameStateManager)
{
	if (gameWorld->isPlaying())
		gameWorld->update();
	else
	{
		delete gameWorld;
		gameStateManager->changeState(new GameOverState());
	}
}