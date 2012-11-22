/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Animation class
	Provides the frame work for sprite animations
*/

#include "Animation.h"
#include "SDL.h"

Animation::Animation(unsigned numberOfFrames, unsigned *durations, bool loop)
{
	frameDurations = new unsigned[numberOfFrames];
	
	//Copy the frame information in
	for (unsigned i=0; i < numberOfFrames; i++)
		frameDurations[i] = durations[i];

	maxFrames = numberOfFrames;
	currentFrame = 0;
	lastUpdate = 1; //frames without an update
	looping = loop; //loop the animation
}

//Memory management
Animation::~Animation() {delete frameDurations;}

void Animation::update()
{
	//Advance the frame if it has met it's duration
	if (lastUpdate == frameDurations[currentFrame])
	{
		lastUpdate = 1;
		currentFrame++;
	}
	else
		lastUpdate++;

	//Loop animation
	if(currentFrame == maxFrames && looping)
		currentFrame = 0;
}

int Animation::getCurrentFrame() {return currentFrame;}
bool Animation::finished()
{
	if (!looping)
		return currentFrame == maxFrames;
	else
		return false;
}