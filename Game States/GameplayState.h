/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Gameplay State
	Game state where the game is actually played
*/
#ifndef GAMEPLAYSTATE_H_
#define GAMEPLAYSTATE_H_

#include "GameState.h"
#include "GameWorld.h"
class GameplayState: public GameState
{
private:
	GameWorld* gameWorld;
public:
	GameplayState();
	~GameplayState();
	void display(SDL_Surface* screen);
	void userInput(SDL_Event* event);
	void update(StateManager* gameStateManager);
};

#endif /* GAMEPLAYSTATE_H_ */