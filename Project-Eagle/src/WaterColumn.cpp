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
	sf::Shape line = sf::Shape::Line(this->x1, this->height, this->x2, this->y2, this->thickness, sf::Color(this->r, this->g, this->b, 150));

	this->window->Draw(line);
}

void WaterColumn::setParameters(float h, float th, float s)
{
	this->height = h;
	this->targetHeight = th;
	this->speed = s;
}

void WaterColumn::setCoordinates(float nx1, float ny1, float nx2, float ny2, float t)
{
	this->x1 = nx1;
	this->x2 = nx2;
	this->height = ny1;
	this->y2 = ny2;
	this->thickness = t;
}

void WaterColumn::update(float dampening, float tension)
{
	float x = this->targetHeight - this->height;
	this->speed += tension * x - this->speed * dampening;
	this->height += this->speed;
}

float WaterColumn::returnHeight()
{
	return this->height;
}

void WaterColumn::setSpeed(float speed)
{
	this->speed += speed;
}

void WaterColumn::setHeight(float height)
{
	this->height += height;
}