Squids of the Galaxy
----------------------------
Info:

Squids of the Galaxy is a retro arcade shoot 'em up game I created using C++ with the SDL library 
for my 'Games Programming' portfolio at university in 2011. I received a HD grade of 90 for my work on 
the portfolio, in part due to the work I completed on this game which combined many of the 'spike' assignments 
we completed throughout the semester into one application. I completed some research work on AI 
using several different approaches, in the end settling on using simple finite state machines to get the 
enemy behaviour the way I wanted it.

An example of the AI I implemented to this game is the red, spiky enemies. They will 'camp' on the side of the 
screen opposite to the player until they are near death, and then will charge toward the player in a 'kamikaze' 
attack that inflicts a high amount of damage on the player. The orange squid enemies simply track towards the left 
side of the screen.

----------------------------
Installation instructions:

-To install, extract the files to a folder and run the Squids of the Galaxy.exe file.
-Works on Windows 7


---------------------------

Controls:

UP - move up
DOWN - move down
LEFT - move left
RIGHT - move right
Z - fire weapon
Mouse - navigate menus

Uses SDL 1.2.14
Written in C++, using Visual Studio 2010

-----------------------------
Compile instructions:

-You will need to install SDL 1.2.14 and the extensions: SDL_mixer, SDL_image and SDL_ttf.
-Link to the SDL libraries using the linker settings of your compiler
-If unsure, go to http://lazyfoo.net/SDL_tutorials/lesson01/index.php for detailed
instructions on how to set up SDL for Windows, Linux and Mac for various IDEs such as Visual Studio, Eclipse and CodeBlocks.