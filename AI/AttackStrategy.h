/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Attack Strategy: The enemy constantly
	moves towards the player and shoots.

	Easy for the player to kill.
*/

#ifndef ATTACKSTRATEGY_H_
#define ATTACKSTRATEGY_H_
#include "Strategy.h"
class AttackStrategy: public Strategy
{
private:
	unsigned shootCounter;
	unsigned shootFreq;
public:
	AttackStrategy();
	~AttackStrategy();
	int setXvel();
	bool shoot();
};
#endif /*ATTACKSTRATEGY_H_*/
