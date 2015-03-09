#include "WaterColumn.h"
#include <iostream>

using namespace std;

WaterColumn::WaterColumn(sf::RenderWindow* rw)
	: window(rw)
{
	this->thickness = 1.0;
	this->r = 065;
	this->g = 105;
	this->b = 225;
}

WaterColumn::~WaterColumn()
{
}

void WaterColumn::render()
{
	sf::RectangleShape line;
	line.setSize(sf::Vector2f(this->thickness, this->height));
	line.setPosition(sf::Vector2f(this->x, this->y));
	line.setFillColor(sf::Color(this->r, this->g, this->b, 125));

	this->window->draw(line);
}

void WaterColumn::setParameters(float height, float targetHeight, float speed, float windowHeight)
{
	this->height = height;
	this->targetHeight = targetHeight;
	this->speed = speed;
	this->windowHeight = windowHeight;
}

void WaterColumn::setCoordinates(float x, float y, float thickness, float height)
{
	this->x = x;
	this->y = y;
	this->thickness = thickness;
	this->height = height;
}

void WaterColumn::update(float dampening, float tension)
{
	float x = this->targetHeight - this->y;
	this->speed += tension * x - this->speed * dampening;
	this->y += this->speed;

}

float WaterColumn::returnHeight()
{
	return this->y;
}

void WaterColumn::setSpeed(float speed)
{
	this->speed += speed;
}

void WaterColumn::setHeight(float height)
{
	this->y += height;
}