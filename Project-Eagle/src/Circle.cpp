#include "Circle.h"

Circle::Circle(sf::RenderWindow* rw)
	: window(rw)
{
	this->velocity = 0;

	this->resistance = 0;
}

Circle::~Circle()
{
}

void Circle::setParameters(float x, float y, float radius, int r, int g, int b)
{
	this->x1 = x;
	this->y1 = y;
	this->radius = radius;
	this->r = r;
	this->g = g;
	this->b = b;
}

float Circle::getY()
{
	return this->y1;
}

float Circle::getX()
{
	return this->x1;
}

void Circle::setResistance(float res)
{
	this->resistance = res;
}

void Circle::update()
{
	this->velocity += GRAVITY * VELMODIFIER;

	this->velocity -= this->velocity * this->resistance;

	this->y1 += this->velocity;

}

void Circle::setBounce()
{
	this->bounce = true;
}

float Circle::getVelocity()
{
	return this->velocity;
}

void Circle::render()
{
	sf::Shape crc = sf::Shape::Circle(this->x1, this->y1, this->radius, sf::Color(r, g, b ,255));

	this->window->Draw(crc);
}
