#pragma once
#include <SFML/Graphics.hpp>

class WaterColumn
{
public:
	WaterColumn(sf::RenderWindow* rw);
	~WaterColumn();
	void update(float dampening, float tension);
	void render();
	void setParameters(float height, float targetHeight, float speed, float windowHeight);
	void setCoordinates(float x, float y, float thickness, float height);
	float returnHeight();
	void setSpeed(float speed);
	void setHeight(float height);
private:
	sf::RenderWindow* window;

	float targetHeight, height, windowHeight;
	float speed;
	float x, y;
	float thickness;
	int r, g, b;
};