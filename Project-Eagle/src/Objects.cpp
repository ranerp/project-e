#include "Objects.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Objects::Objects(sf::RenderWindow& rw)
: window(&rw)
{

	this->interval = 3;
	this->columnsNumber = 201;
}

Objects::~Objects()
{
}

int Objects::returnColumns()
{
	return this->columnsNumber;
}

void Objects::render()
{
	this->iter = this->circles.begin();
	while(this->iter != this->circles.end())
	{
		(*this->iter)->update();
		(*this->iter)->render();

		this->iter++;
	}

	this->water->render();
}

void Objects::addWater()
{
	this->water = new Water(this->window);

	this->water->setColumns(this->columnsNumber);
}

vector<Circle*>* Objects::returnCircleVector()
{
	return &this->circles;
}

Circle* Objects::addCircle(float x, float y, float radius, int r, int g, int b)
{
	Circle* c = new Circle(this->window);
	c->setParameters(x, y, radius, r, g, b);

	this->circles.push_back(c);

	return c;
}