/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Camp Strategy: The enemy waits where it
	spawns and shoots at the player without
	moving.
*/

#ifndef CAMPSTRATEGY_H_
#define CAMPSTRATEGY_H_
#include "Strategy.h"
class CampStrategy: public Strategy
{
private:
	unsigned shootCounter;
	unsigned shootFreq;
public:
	CampStrategy();
	~CampStrategy();
	int setXvel();
	bool shoot();
};
#endif /*STRATEGY_H_*/
