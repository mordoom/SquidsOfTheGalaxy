/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Kamikaze Strategy: The enemy just swims
	at full speed toward the player in a last
	ditch attempt to harm him
*/

#include "KamikazeStrategy.h"
#include "SotG.h"
KamikazeStrategy::KamikazeStrategy()
{
	//Nothing to do..
}

KamikazeStrategy::~KamikazeStrategy(){}

//Tell enemy to move - fast
int KamikazeStrategy::setXvel(){return ENEMYSPEED*2;}

//Tell enemy to shoot if required
bool KamikazeStrategy::shoot()
{
	//Enemy doesn't shoot in this strategy
	return false;
}