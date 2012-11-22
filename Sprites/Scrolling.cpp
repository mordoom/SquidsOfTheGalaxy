/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Scrolling class
	Parallax scrolling background
*/

#include "Scrolling.h"
#include "SotG.h"

Scrolling::Scrolling()
{
	//Set up scrolling
	background = IMG_Load("Images/bg-water.png");
	foreground = IMG_Load("Images/bg-floor.png");

	bgX = 0;
	fgX = 0;
	fgY = WINHEIGHT-220;
}

void Scrolling::applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;
    
    //Get offsets
    offset.x = x;
    offset.y = y;
    
    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void Scrolling::draw(SDL_Surface* screen)
{
	//Scroll background & foreground
	bgX -= 4;
	fgX -= 8;
        
    //If the background has gone too far
    if( bgX <= -background->w )
		bgX = 0;

	//If the foreground has gone too far
    if( fgX <= -foreground->w )
        fgX = 0;

	//Show the background
    applySurface( bgX, 0, background, screen );
    applySurface( bgX + background->w, 0, background, screen );

	//Show foreground
	applySurface( fgX, fgY, foreground, screen );
    applySurface( fgX + foreground->w, fgY, foreground, screen );
}

Scrolling::~Scrolling()
{
	//Free images
	SDL_FreeSurface(background);
	SDL_FreeSurface(foreground);
}