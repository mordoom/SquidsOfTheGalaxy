/*
	The input manager for handling
	the key mappings
*/

#include "InputManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

InputManager::InputManager()
{
	//Load mappings from text file "input.txt"
	ifstream fInput;
	
	fInput.open("input.txt");
	if (fInput.good())
	{
		string inputLine;
		while (getline(fInput, inputLine))
		{
			string input;
			stringstream stream(inputLine);

			//Get dir
			getline(stream, input, ' ');
			char dir = input[0];

			//Get keyId
			getline(stream, input, '\n');
			int ascii = atoi(input.c_str());

			//Map key
			keyMap.insert(make_pair<int,char>(ascii, dir));
		}
	}
	else
		printf("Sorry, there was an error loading the key mapping data!");

	fInput.close();
}

//Convert ascii value to a direction by finding it in the map
const char InputManager::handleInput(int key) const
{	
	return keyMap.find(key)->second;
}