/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Strategy class, provides an abstract class
	for enemy AI strategies to inherit from.
*/

#ifndef STRATEGY_H_
#define STRATEGY_H_
class Strategy
{
private:
public:
	Strategy();
	virtual int setXvel() = 0;
	virtual bool shoot() = 0;
};
#endif /*STRATEGY_H_*/
