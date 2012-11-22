/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Sound manager
	Manages music and sound effects
*/
#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_
#include "SDL_mixer.h"
#include <map>
#include <stdio.h>

class SoundManager
{
private:
	static SoundManager* _instance;
protected:
	SoundManager();
public: 
	static SoundManager* Instance();
	~SoundManager();
	void playSound(char* sound);
};
#endif /*SOUNDMANAGER_H_*/