#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Window {

	public:
		Window();
		Window(const std::string &title, const sf::Vector2u &size);
		~Window();

		void beginDraw(); 
		void endDraw(); 

		void update();

		bool isDone();
		sf::Vector2u getWindowSize();

		void draw(sf::Drawable &drawable);
	
	private:
		void setup(const std::string &title, const sf::Vector2u &size);
		void destroy();
		void create();

		sf::RenderWindow m_window;
		sf::Vector2u m_windowSize;
		std::string m_windowTitle;
		bool m_isDone;
		bool m_isFullScreen;

};

#endif



