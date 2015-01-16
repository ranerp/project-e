#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class Fps
{
public:
	Fps(sf::RenderWindow &rw);
	~Fps();
	void show();
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	sf::Font font;
	sf::String text;
	int frameRate;
};