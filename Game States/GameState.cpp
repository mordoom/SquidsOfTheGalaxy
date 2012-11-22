/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game State
	Abstract class that defines a state of the application
*/

#include "StateManager.h"
#include "GameState.h"

GameState::GameState(){}

//Virtual methods
void GameState::display(SDL_Surface* screen){}
void GameState::userInput(SDL_Event* event){}
void GameState::update(StateManager* gameStateManager){}
