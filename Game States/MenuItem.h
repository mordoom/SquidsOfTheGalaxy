/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Menu Item
	An Item in a game menu that can be clicked
*/

#ifndef MENUITEM_H_
#define MENUITEM_H_
#include "SDL_ttf.h"

class MenuItem
{
private:
	//Text
	SDL_Surface* title;

	//Font
	TTF_Font *titleFont;
	
	//Button co-ordinates and dimensions
	SDL_Rect clip;
public:
	MenuItem(const char* text, TTF_Font* font, SDL_Color color,int x, int y);
	SDL_Rect& getClip();
	void display(SDL_Surface* screen);
};

#endif /* MENUITEM_H_ */