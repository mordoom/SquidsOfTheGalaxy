/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Attack Strategy: The enemy constantly
	moves towards the player and shoots.

	Easy for the player to kill.
*/

#include "AttackStrategy.h"
#include "SDL.h"
#include "SotG.h"
AttackStrategy::AttackStrategy()
{
	shootCounter = SDL_GetTicks();
	shootFreq = ATTACKFREQ;
}

AttackStrategy::~AttackStrategy(){}

//Tell enemy to not move
int AttackStrategy::setXvel(){return ENEMYSPEED;}

//Tell enemy to shoot if required
bool AttackStrategy::shoot()
{
	//If it's not time to shoot, return false
	if( SDL_GetTicks() < (shootCounter+shootFreq) )
		return false;
	
	//Update timer
	shootCounter = SDL_GetTicks();

	//Tell the enemy its time to shoot
	return true;
}