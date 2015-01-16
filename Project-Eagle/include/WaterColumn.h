#pragma once
#include <SFML/Graphics.hpp>

class WaterColumn
{
public:
	WaterColumn(sf::RenderWindow* rw);
	~WaterColumn();
	void update(float dampening, float tension);
	void render();
	void setParameters(float h, float th, float s);
	void setCoordinates(float x1, float x2, float y1, float y2, float t);
	float returnHeight();
	void setSpeed(float speed);
	void setHeight(float height);
private:
	sf::RenderWindow* window;

	float targetHeight;
	float height;
	float speed;
	float x1, x2, y2, y1;
	float thickness;
	int r, g, b;
};