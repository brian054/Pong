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

Game::Game(): m_window("Pong", sf::Vector2u(WIDTH, HEIGHT)) {
	m_increment = sf::Vector2f(10.f, 10.f); 

	m_computer.setSize(sf::Vector2f(m_paddleWidth, m_paddleHeight));
	m_computer.setPosition(1200 - 75, 900 / 2);

	m_player.setSize(sf::Vector2f(m_paddleWidth, m_paddleHeight));
	m_player.setPosition(50,50);
	
	m_ball.setSize(sf::Vector2f(m_ballWidth, m_ballHeight));
	resetBall();
	m_ball.setFillColor(sf::Color::Blue);

	resetGame();

	if (!m_font.loadFromFile("arial.ttf")) {
		//Error
	}

	m_scoreText.setFont(m_font);
	m_scoreText.setString(std::to_string(m_playerScore) + " - " + std::to_string(m_computerScore));
	m_scoreText.setCharacterSize(70);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition(530.f , 0.f);
}

Game::~Game() {}

void Game::update() {
	m_window.update(); ///Update window events
	
	float timestep = 1.0f / 60;

	if (m_elapsed.asSeconds() >= timestep) {
		handleInput();
		moveBall();
		moveComputer();
		checkCollisionPaddle(m_player);
		checkCollisionPaddle(m_computer);
		ballCollisionWindow();
		m_elapsed -= sf::seconds(timestep);
	}
}

Window *Game::getWindow() {
	return &m_window;
}

void Game::handleInput() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (m_player.getPosition().y >= 0)) {
		m_player.move(0.f, -10.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (m_player.getPosition().y + m_paddleHeight <= HEIGHT)) {
		m_player.move(0.f, 10.f);
	}
}

void Game::render() {
	m_window.beginDraw(); //Clear
	m_window.draw(m_scoreText);
	m_window.draw(m_ball);
	m_window.draw(m_computer);
	m_window.draw(m_player);
	m_window.endDraw(); //Display
}

sf::Time Game::getElapsed() {
	return m_elapsed;
}

void Game::restartClock() {
	m_elapsed += m_clock.restart();
}

void Game::moveComputer() {
		if ((m_ball.getPosition().y < m_computer.getPosition().y + (m_paddleHeight / 2)) && (m_computer.getPosition().y >= 0) ) {
            m_computer.move(0.f, -8.5f);
        }
        if ((m_ball.getPosition().y > m_computer.getPosition().y + (m_paddleHeight / 2)) && (m_computer.getPosition().y + m_paddleHeight <= HEIGHT)) {
            m_computer.move(0.f, 8.5f);
        }
}

void Game::moveBall() {
	m_ball.move(m_increment);
}

void Game::checkCollisionPaddle(sf::RectangleShape paddle) {
	if ((m_ball.getPosition().x < paddle.getPosition().x + m_paddleWidth) && (m_ball.getPosition().x + m_ballWidth > paddle.getPosition().x)
            && (m_ball.getPosition().y < paddle.getPosition().y + m_paddleHeight) && (m_ball.getPosition().y + m_ballHeight > paddle.getPosition().y)) {	
	       	m_increment.x = -m_increment.x;
    }	
}

void Game::ballCollisionWindow() {
	if ((m_ball.getPosition().y + (m_ballHeight) > HEIGHT && m_increment.y > 0)
		       	|| ( m_ball.getPosition().y < 0 && m_increment.y < 0 ) ) {
            m_increment.y = -m_increment.y;
    }
	
	//Check if someone scored (do this in a separate function)
	if (m_ball.getPosition().x < 0) { increaseScore(m_computerScore); }
	if ((m_ball.getPosition().x + m_ballWidth) > WIDTH) { increaseScore(m_playerScore); }
}

void Game::resetBall() {
	m_ball.setPosition((m_window.getWindowSize().x / 2) - m_ballWidth, 
			(m_window.getWindowSize().y / 2) - m_ballHeight);
}

void Game::resetGame() {
	m_playerScore = 0;
	m_computerScore = 0;

	//reset player and computer position
	
}

void Game::increaseScore(int &score) {
	score++;
	m_increment.x = -m_increment.x;
	m_scoreText.setString(std::to_string(m_playerScore) + " - " + std::to_string(m_computerScore));
	resetBall();	
}
