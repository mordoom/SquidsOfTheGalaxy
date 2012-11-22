/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Menu Item
	An Item in a game menu that can be clicked
*/

#include "MenuItem.h"
#include "SDL.h"
MenuItem::MenuItem(const char* text, TTF_Font* font, SDL_Color color, int x, int y)
{
	title = TTF_RenderText_Solid( font, text, color);
	clip.x = x;
	clip.y = y;
}

SDL_Rect& MenuItem::getClip() {return clip;}

void MenuItem::display(SDL_Surface* screen)
{
	SDL_BlitSurface( title, NULL, screen, &clip );
}