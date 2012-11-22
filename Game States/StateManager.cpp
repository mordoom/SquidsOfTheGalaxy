/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	State Manager
	Manages the game states
*/

#include "GameState.h"
#include "StateManager.h"
#include <stdio.h>

//Singleton instance
StateManager* StateManager::_instance = NULL;

//Constructor
StateManager::StateManager()
{
	running = true;
	currentState = (GameState*)0;
}

//Destructor
StateManager::~StateManager()
{
	delete _instance;
}

//Singleton pattern
StateManager* StateManager::Instance()
{
	if (_instance == NULL)
		_instance = new StateManager();

	return _instance;
}

void StateManager::changeState(GameState* state)
{
	//Prevent memory leaks
	if (currentState != (GameState*)0)
		delete currentState;
	
	currentState = state;
}

void StateManager::display(SDL_Surface* screen) { currentState->display(screen); }

void StateManager::userInput(SDL_Event* event) { currentState->userInput(event); }

void StateManager::update() { currentState->update(this); }

bool StateManager::isRunning() { return running; }

void StateManager::quit() { running = false; }