/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Animation class
	Provides the frame work for sprite animations
*/

#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation
{
private:
	unsigned currentFrame;
	unsigned *frameDurations;
	unsigned maxFrames;
	unsigned lastUpdate;
	bool looping;
public: 
	Animation(unsigned numberOfFrames, unsigned *durations, bool loop);
	~Animation();
	void update();
	int getCurrentFrame();
	bool finished();
};
#endif /*ANIMATION_H_*/