/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Kamikaze Strategy: The enemy just swims
	at full speed toward the player in a last
	ditch attempt to harm him
*/

#ifndef KAMIKAZESTRATEGY_H_
#define KAMIKAZESTRATEGY_H_
#include "Strategy.h"
class KamikazeStrategy: public Strategy
{
private:
	//none
public:
	KamikazeStrategy();
	~KamikazeStrategy();
	int setXvel();
	bool shoot();
};
#endif /*STRATEGY_H_*/
