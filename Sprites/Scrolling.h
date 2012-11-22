/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Scrolling class
	Parallax scrolling background
*/

#ifndef SCROLLING_H_
#define SCROLLING_H_
#include "SDL.h"
#include "SDL_image.h"
class Scrolling
{
private:
	SDL_Surface* background;
	SDL_Surface* foreground;
	int bgX;
	int fgX;
	int fgY;
public: 
	Scrolling();
	~Scrolling();
	void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	void draw(SDL_Surface* screen);
};
#endif /*SCROLLING_H_*/