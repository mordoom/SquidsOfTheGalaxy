/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Game Over state
	Defines the screen that is displayed when there is a game over
*/

#include "GameOverState.h"
#include "StateManager.h"
#include "SDL_image.h"
#include <stdio.h>

//Menu Items
#include "GameplayState.h"
#include "MainMenuState.h"

//Constructor
GameOverState::GameOverState()
{
	//Default value
	userSelection = 0;

	//Initialize SDL_ttf
	TTF_Init();

	//Font
	titleFont = TTF_OpenFont( "arcade classic.ttf", 48 );
	menuFont = TTF_OpenFont( "emulogic.ttf", 18 );

	//Colors
	SDL_Color whiteText = { 255, 255, 255 };
	SDL_Color redText = { 255, 0, 0 };

	//Text
	gameOver = TTF_RenderText_Solid( titleFont, "GAME OVER", redText );

	//Text positions
    titleOffset.x = 250;
    titleOffset.y = 100;

	//Menu Initialisation
	int menuPos = 450;
	menuItems.push_back(MenuItem("Play Again", menuFont, whiteText, menuPos, 200));
	menuItems.push_back(MenuItem("Exit to Menu", menuFont, whiteText, menuPos, 250));
}

GameOverState::~GameOverState()
{
	//Free surfaces
    SDL_FreeSurface(gameOver);

	//Close the fonts
    TTF_CloseFont( titleFont );
	TTF_CloseFont( menuFont );

	//clear menu
	menuItems.clear();
}

//Display the menu
void GameOverState::display(SDL_Surface* screen)
{
	//Background
	SDL_FillRect( screen, 0, 0 );
	
	//Render text
	SDL_BlitSurface( gameOver, NULL, screen, &titleOffset );

	//Render menu
	for (unsigned i=0; i< menuItems.size(); i++)
		menuItems[i].display(screen);
}

void GameOverState::userInput(SDL_Event* event)
{
	//If the left mouse button is clicked
	if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT)
	{
		//Get the mouse offsets
		int x = event->button.x;
        int y = event->button.y;
        
		for (unsigned i=0; i< menuItems.size();i++)
		{
			SDL_Rect clip = menuItems[i].getClip();
			//If the mouse is over the button
			if( ( x > clip.x ) && ( x < clip.x + clip.w ) && ( y > clip.y ) && ( y < clip.y + clip.h ) )
				//Set the selection for the update
				userSelection = i+1;
		}
	}
}

void GameOverState::update(StateManager* gameStateManager)
{
	//Change to selected menu option
	switch(userSelection)
	{
		default:
			break;
		case 1:
			gameStateManager->changeState(new GameplayState());
			break;
		case 2:
			gameStateManager->changeState(new MainMenuState());
			break;
	}
}