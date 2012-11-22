/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Main Menu state
	Defines the main menu appearance and behaviour
*/
#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_
#include "GameState.h"
#include "MenuItem.h"
#include "SDL_ttf.h"
#include <vector>

class MainMenuState: public GameState
{
private:
	int userSelection;
	//Text
	SDL_Surface* title;
	SDL_Surface* copyright;

	//Background
	SDL_Surface* background;

	//Menu
	std::vector<MenuItem> menuItems;

	//Fonts
	TTF_Font *titleFont;
	TTF_Font *menuFont;
	
	//Text offsets
	SDL_Rect titleOffset;
	SDL_Rect copyrightOffset;
public:
	MainMenuState();
	~MainMenuState();
	void display(SDL_Surface* screen);
	void userInput(SDL_Event* event);
	void update(StateManager* gameStateManager);
};

#endif /* MAINMENUSTATE_H_ */