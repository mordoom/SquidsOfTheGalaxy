/*
	Squids of the Galaxy
	-----------------------------------
	By Alex Mordue 7182600

	Header file, stores game constants
*/
#ifndef SOTG_H_
#define SOTG_H_

//Window dimensions
static int WINHEIGHT = 675;
static int WINWIDTH = 1200;

//Sprite dimensions
static int PLAYERSIZE = 128;
static int ENEMYSIZE = 128;
static int BULLETSIZE = 64;

//Frame Rate
static unsigned FPS = 1000/60; //60 fps

//Entity speeds
static int PLAYERSPEED = 5;
static int ENEMYSPEED = PLAYERSPEED;
static int BULLETSPEED = PLAYERSPEED*2;

//Hit points
static int PLAYER_HP = 10;

//Spawn frequencies
static unsigned ENEMYFREQ  = 1500;
static unsigned ENEMYFREQINC = 10;
static unsigned ENEMYSPAWNMAX = 500;
static unsigned SMARTENEMYSPAWN = 1000;

//Enemy strength
static int ENEMYHP = 3;
static int SMARTENEMYHP = 10;

//Enemy Shooting Freq
static int ATTACKFREQ = 1250;

//Collision types
enum COLLISIONTYPE {NONE, HIT, PICKUP};

//Sprite types
enum SPRITETYPE {PLAYER, ENEMY, ENEMYBULLET, PLAYERBULLET, POWERUP};

//Player states (for movement animation)
enum PLAYERSTATE {IDLE, HORIZONTAL, VERTICAL};

//Sprite states
enum SPRITESTATE {ALIVE, DYING, DEAD};

#endif /* SOTG_H_*/