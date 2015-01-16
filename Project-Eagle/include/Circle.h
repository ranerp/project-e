#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define GRAVITY 3.8
#define VELMODIFIER 0.25

class Circle
{
public:
	Circle(sf::RenderWindow* rw);
	~Circle();
	void render();
	void setParameters(float x, float y, float radius, int r, int g, int b);
	void update();
	float getY();
	float getX();
	void setResistance(float res);
	float getVelocity();
	void setBounce();
private:
	float x1, y1, radius;
	int r, g, b;
	float velocity;
	float resistance;

	bool bounce;

	sf::Clock clock;

	sf::RenderWindow* window;

};