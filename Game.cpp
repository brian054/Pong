/*
 *
 * Game.cpp
 * Purpose: Implementation of Game.h
 *
 */

#include "Game.h"
#include <iostream>

using namespace std;

const int HEIGHT = 800;
const int WIDTH = 1200;

Game::Game(): window("Pong", sf::Vector2u(WIDTH, HEIGHT)) {
	increment = sf::Vector2f(10.f, 10.f);

	computer.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	computer.setPosition(1200 - 75, 900 / 2);

	player.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	player.setPosition(50,50);
	
	ball.setSize(sf::Vector2f(ballWidth, ballHeight));
	resetBall();
	ball.setFillColor(sf::Color::Blue);

	resetGame();

	if (!font.loadFromFile("arial.ttf")) {
		//Error
	}

	scoreText.setFont(font);
	scoreText.setString(std::to_string(playerScore) + " - " + std::to_string(computerScore));
	scoreText.setCharacterSize(70);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(530.f , 0.f);
}

Game::~Game() {}

void Game::Update() {
	window.update(); ///Update window events
	
	float timestep = 1.0f / 60;

	if (elapsed.asSeconds() >= timestep) {
		HandleInput();
		moveBall();
		moveComputer();
		checkCollisionPaddle(player);
		checkCollisionPaddle(computer);
		ballCollisionWindow();
		elapsed -= sf::seconds(timestep);
	}
}

Window *Game::getWindow() {
	return &window;
}

void Game::HandleInput() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (player.getPosition().y >= 0)) {
		player.move(0.f, -10.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (player.getPosition().y + paddleHeight <= HEIGHT)) {
		player.move(0.f, 10.f);
	}
}

void Game::Render() {
	window.beginDraw(); //Clear
	window.draw(scoreText);
	window.draw(ball);
	window.draw(computer);
	window.draw(player);
	window.endDraw(); //Display
}

sf::Time Game::GetElapsed() {
	return elapsed;
}

void Game::RestartClock() {
	elapsed += clock.restart();
}

void Game::moveComputer() {
		if ((ball.getPosition().y < computer.getPosition().y + (paddleHeight / 2)) && (computer.getPosition().y >= 0) ) {
            computer.move(0.f, -8.5f);
        }
        if ((ball.getPosition().y > computer.getPosition().y + (paddleHeight / 2)) && (computer.getPosition().y + paddleHeight <= HEIGHT)) {
            computer.move(0.f, 8.5f);
        }
}

void Game::moveBall() {
	ball.move(increment);
}

void Game::checkCollisionPaddle(sf::RectangleShape paddle) {
	if ((ball.getPosition().x < paddle.getPosition().x + paddleWidth) && (ball.getPosition().x + ballWidth > paddle.getPosition().x)
            && (ball.getPosition().y < paddle.getPosition().y + paddleHeight) && (ball.getPosition().y + ballHeight > paddle.getPosition().y)) {	
	       	increment.x = -increment.x;
    }	
}
