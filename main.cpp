/*
 * ToDo:
 *	- clean up code
 *	- fix collision direction (Direction influencing ball movement)
 *	- Add Score System, Restart, etc. (Do first) 
 *	- Add Main Menu
 *	- Add Difficulties (Easy, Medium, Hard)
 *	- Add 2 player mode
 *
 */

#include "Game.h"

int main() {
	Game game;
	while (!game.getWindow()->isDone()) {
		//game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return 0;
}
