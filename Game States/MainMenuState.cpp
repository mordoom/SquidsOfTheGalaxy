/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Main Menu state
	Defines the main menu appearance and behaviour
*/

#include "MainMenuState.h"
#include "StateManager.h"
#include "SDL_image.h"
#include <stdio.h>

//Menu Items
#include "GameplayState.h"
//Did not have time to create these game states
//#include "OptionsState.h"
//#include "HighScoresState.h"

//Constructor
MainMenuState::MainMenuState()
{
	//Default value
	userSelection = 0;

	//Initialize SDL_ttf
	TTF_Init();

	//Font
	titleFont = TTF_OpenFont( "arcade classic.ttf", 48 );
	menuFont = TTF_OpenFont( "emulogic.ttf", 18 );

	//Background
	background = IMG_Load("Images/background.png");

	//Colors
	SDL_Color whiteText = { 255, 255, 255 };
	SDL_Color blackText = { 0, 0, 0 };
	SDL_Color redText = { 255, 0, 0 };

	//Text
	title = TTF_RenderText_Solid( titleFont, "SQUIDS of the GALAXY", redText );
	copyright = TTF_RenderText_Solid( menuFont, "(c) 2011 Alex Mordue", blackText );

	//Text positions
    titleOffset.x = 250;
    titleOffset.y = 100;
	copyrightOffset.x = 400;
    copyrightOffset.y = 550;

	//Menu Initialisation
	int menuPos = 450;
	menuItems.push_back(MenuItem("Play", menuFont, whiteText, menuPos, 200));
	menuItems.push_back(MenuItem("Options", menuFont, blackText, menuPos, 250));
	menuItems.push_back(MenuItem("High Scores", menuFont, blackText, menuPos, 300));
	menuItems.push_back(MenuItem ("Quit", menuFont, whiteText, menuPos, 350));
}

MainMenuState::~MainMenuState()
{
	//Free surfaces
    SDL_FreeSurface(title);
	SDL_FreeSurface(copyright);
	SDL_FreeSurface(background);

	//Close the fonts
    TTF_CloseFont( titleFont );
	TTF_CloseFont( menuFont );

	//clear menu
	menuItems.clear();
}

//Display the menu
void MainMenuState::display(SDL_Surface* screen)
{
	//Background
	SDL_BlitSurface( background, NULL, screen, NULL);
	
	//Render text
	SDL_BlitSurface( title, NULL, screen, &titleOffset );
	SDL_BlitSurface( copyright, NULL, screen, &copyrightOffset );

	//Render menu
	for (unsigned i=0; i< menuItems.size(); i++)
		menuItems[i].display(screen);
}

void MainMenuState::userInput(SDL_Event* event)
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

void MainMenuState::update(StateManager* gameStateManager)
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
			//gameStateManager->changeState(new OptionsState());
			break;
		case 3:
			//gameStateManager->changeState(new HighScoresState());
			break;
		case 4:
			gameStateManager->quit();
			break;
	}
}