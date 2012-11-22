/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game State
	Abstract class that defines a state of the application
*/

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include "SDL.h"

class StateManager;
class GameState
{
protected:
	GameState();
public:
	virtual void display(SDL_Surface* screen) = 0;
	virtual void userInput(SDL_Event* event) = 0;
	virtual void update(StateManager* gameStateManager) = 0;
};

#endif /* GAMESTATE_H_ */