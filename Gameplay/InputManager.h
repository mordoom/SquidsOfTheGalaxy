/*
	The input manager for handling
	the key mappings
*/

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_
#include "SDL.h"
#include <map>

class InputManager
{
private:
	std::map<int, char> keyMap;
public:
    InputManager();
	const char handleInput(int key) const;
};
#endif /* INPUTMANAGER_H_ */