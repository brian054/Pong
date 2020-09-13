#ifndef WINDOW_H
#define WINDOW_H
#include "Window.h"

// Game
class Game {
	public:
		Game();
		~Game();

		sf::Time getElapsed();
		void restartClock();
		void handleInput();
		void update();
		void render();
		Window *getWindow();
	
	private:
		Window window;

		sf::Vector2f increment;
		sf::Clock clock;
		sf::Time elapsed;

		const int paddleWidth = 25.f;
		const int paddleHeight = 130.f;
		const int ballWidth = 25.f;
		const int ballHeight = 25.f;

		int playerScore;
		int computerScore;

		sf::RectangleShape computer;
		sf::RectangleShape player;
		sf::RectangleShape ball;

		sf::Font font;
		sf::Text scoreText;

		void moveComputer();
		void moveBall();
		void checkCollisionPaddle(sf::RectangleShape paddle);
		void ballCollisionWindow();
		void resetBall();
		void resetGame();
		void increaseScore(int &score);
};

#endif