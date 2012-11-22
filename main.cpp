/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Main file
	Sets up SDL and contains the main game loop.
*/

#include "SDL.h"
#include "SotG.h"
#include "StateManager.h"
#include "MainMenuState.h"

SDL_Event event;

int main( int argc, char* args[] )
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
	//Set up screen
	SDL_Surface* screen = NULL;
    screen = SDL_SetVideoMode( WINWIDTH, WINHEIGHT, 32, SDL_SWSURFACE );
	SDL_WM_SetCaption("Squids of the Galaxy", NULL);

	//State Mananger
	StateManager* stateManager = StateManager::Instance();
	
	//Create main menu
	MainMenuState* mainMenu = new MainMenuState();
	stateManager->changeState(mainMenu);

	//Main game loop
	while (stateManager->isRunning())
	{
		//USER INPUT
	    while (SDL_PollEvent(&event))
		{	
			if (event.type == SDL_QUIT)
				stateManager->quit();

			//Take user input
			stateManager->userInput(&event);
		}

		//UPDATE
		stateManager->update();

		//RENDER
		stateManager->display(screen);
		if (SDL_Flip(screen) == -1)
			return 1;
	}
	
	//Quit SDL
    SDL_Quit();
	return 0;    
}