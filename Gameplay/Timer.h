/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Timer class
	Manages timing in the SotG game (Frames per second)
*/

#ifndef TIMER_H_
#define TIMER_H_
class Timer
{
private:
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;
    
public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    int get_ticks();
	void update();
    bool is_started();
    bool is_paused();    
};
#endif /*TIMER_H_*/