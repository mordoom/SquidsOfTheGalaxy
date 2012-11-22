/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Sound manager
	Manages music and sound effects
*/

#include "SoundManager.h"

//Singleton instance
SoundManager* SoundManager::_instance = NULL;

SoundManager::SoundManager()
{
	//Initialize SDL_mixer
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	//The sound effects that will be used
	Mix_Chunk *test = NULL;

	//Load the sound effects
   // test = Mix_LoadWAV( "Sounds/shooting.mp3" );
	//May need to do a spike for using mp3 as wav files are too large
}

//Singleton pattern
SoundManager* SoundManager::Instance()
{
	if (_instance == NULL)
		_instance = new SoundManager();

	return _instance;
}
/*
void playSound(string sound)
{
	//find string in map


	//Play chunk
	Mix_PlayChannel( -1, sound, 0 );
}
*/
//Destructor
SoundManager::~SoundManager()
{
	//Free the sound effects
    //Mix_FreeChunk( allofourmeat );

	//Quit SDL_mixer
    Mix_CloseAudio();

	delete _instance;
}