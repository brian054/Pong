/*
 * ToDo:
 * 	- Add State Manager (Menu, Pause, etc.)
 *	- clean up and organize code
 *	- fix collision direction (Direction influencing ball movement)
 *	- Add Score System, Restart, etc. (Do first) 
 *	- Add Difficulties (Easy, Medium, Hard)
 *	- Add 2 player mode
 *
 */
#include "Game.h"

int main() {
	Game game;
	while (!game.getWindow()->isDone()) {
		//game.HandleInput();
		game.update();
		game.render();
		game.restartClock();
	}
	return 0;
}
