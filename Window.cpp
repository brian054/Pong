/*
 *
 * Window.cpp
 * Purpose: Implementation of Window.h
 *
 */
#include "Window.h"

Window::Window() { 
	setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &title, const sf::Vector2u &size) {
	setup(title, size);
}

Window::~Window() { destroy(); }

void Window::setup(const std::string &title, const sf::Vector2u &size) {
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullScreen = false;
	m_isDone = false;
	create();
}

void Window::create() {
	m_window.create({ m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, sf::Style::Default);
}

void Window::destroy() {
	m_window.close();
}

void Window::update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isDone = true;
		} 
	}
}

void Window::beginDraw() {
	m_window.clear(sf::Color::Black);
}

void Window::endDraw() {
	m_window.display();
}

bool Window::isDone() {
	return m_isDone;
}

sf::Vector2u Window::getWindowSize() {
	return m_windowSize;
}

void Window::draw(sf::Drawable &drawable) {
	m_window.draw(drawable);
}





