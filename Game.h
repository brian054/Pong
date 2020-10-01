#ifndef GAME_H
#define GAME_H
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
		void moveComputer();
		void moveBall();
		void checkCollisionPaddle(sf::RectangleShape paddle);
		void ballCollisionWindow();
		void resetBall();
		void resetGame();
		void increaseScore(int &score);

		Window m_window;

		sf::Vector2f m_increment;
		sf::Clock m_clock;
		sf::Time m_elapsed;

		const int m_paddleWidth = 25.f;
		const int m_paddleHeight = 130.f;
		const int m_ballWidth = 25.f;
		const int m_ballHeight = 25.f;

		int m_playerScore;
		int m_computerScore;

		sf::RectangleShape m_computer;
		sf::RectangleShape m_player;
		sf::RectangleShape m_ball;

		sf::Font m_font;
		sf::Text m_scoreText;
};

#endif