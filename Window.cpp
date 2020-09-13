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
	windowTitle = title;
	windowSize = size;
	w_isFullScreen = false;
	w_isDone = false;
	create();
}

void Window::create() {
	window.create({ windowSize.x, windowSize.y, 32}, windowTitle, sf::Style::Default);
}

void Window::destroy() {
	window.close();
}

void Window::update() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			w_isDone = true;
		} 
	}
}

void Window::beginDraw() {
	window.clear(sf::Color::Black);
}

void Window::endDraw() {
	window.display();
}

bool Window::isDone() {
	return w_isDone;
}

sf::Vector2u Window::getWindowSize() {
	return windowSize;
}

void Window::draw(sf::Drawable &drawable) {
	window.draw(drawable);
}





