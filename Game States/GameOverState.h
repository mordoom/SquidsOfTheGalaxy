/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game Over state
	Defines the screen that is displayed when there is a game over
*/
#ifndef GAMEOVERSTATE_H_
#define GAMEOVERSTATE_H_
#include "GameState.h"
#include "MenuItem.h"
#include "SDL_ttf.h"
#include <vector>

class GameOverState: public GameState
{
private:
	int userSelection;
	//Game Over text
	SDL_Surface* gameOver;

	//Menu
	std::vector<MenuItem> menuItems;

	//Fonts
	TTF_Font *titleFont;
	TTF_Font *menuFont;
	
	//Text offsets
	SDL_Rect titleOffset;
public:
	GameOverState();
	~GameOverState();
	void display(SDL_Surface* screen);
	void userInput(SDL_Event* event);
	void update(StateManager* gameStateManager);
};

#endif /* GAMEOVERSTATE_H_ */