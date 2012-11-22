/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Camp Strategy: The enemy waits where it
	spawns and shoots at the player without
	moving.
*/

#include "CampStrategy.h"
#include "SDL.h"
#include "SotG.h"
CampStrategy::CampStrategy()
{
	shootCounter = SDL_GetTicks();
	shootFreq = ATTACKFREQ;
}

CampStrategy::~CampStrategy(){}

//Tell enemy to not move
int CampStrategy::setXvel(){return 0;}

//Tell enemy to shoot if required
bool CampStrategy::shoot()
{
	//If it's not time to shoot, return false
	if( SDL_GetTicks() < (shootCounter+shootFreq) )
		return false;
	
	//Update timer
	shootCounter = SDL_GetTicks();

	//Tell the enemy its time to shoot
	return true;
}