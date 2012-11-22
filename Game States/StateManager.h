/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	State Manager
	Manages the game states
*/

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_
#include "SDL.h"
class GameState;

class StateManager
{
protected:
	StateManager();
private:
	static StateManager* _instance;
	bool running;
	GameState* currentState;
public:
	static StateManager* Instance();
	~StateManager();
	void changeState(GameState* state);
	void display(SDL_Surface* screen);
	void userInput(SDL_Event* event);
	void update();
	bool isRunning();
	void quit();
};
#endif /* STATEMANAGER_H_ */