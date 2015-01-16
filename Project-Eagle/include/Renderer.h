#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Fps.h"
#include "CollisionDetector.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	bool initialize();
	void run();
	void clearScreen();
	void displayScreen();
	void setBackgroundColor(int red, int blue, int green);
private:
	void render();

	sf::RenderWindow window;
	Objects* objects;

	CollisionDetector* cd;

	Fps* fps;

	int r, g, b;

	enum State {Initialized, Running, Paused, Exiting};

	State renderState;
};