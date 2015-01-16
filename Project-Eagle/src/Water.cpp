#include "Water.h"
#include <iostream>

Water::Water(sf::RenderWindow* rw)
: window(rw)
{
	this->dampening = 0.025f;
	this->tension = 0.025f;
	this->spread = 0.3f;
}

Water::~Water()
{
}

void Water::setColumns(int colNmbr)
{
	this->colNumbers = colNmbr;

	this->scale = this->window->GetWidth() / (this->colNumbers - 1);

	for(int i = 0; i < this->colNumbers; i++)
	{
		WaterColumn* w = new WaterColumn(this->window);

		w->setParameters(340, 340, 0);
		w->setCoordinates((i - 1) * this->scale , 340, (i - 1) * this->scale, this->window->GetHeight(), this->scale);

		this->columns.push_back(w);
	}
}

void Water::update()
{
	this->it = this->columns.begin();

	while(it != this->columns.end())
	{
		(*it)->update(this->dampening, this->tension);
		this->it++;
	}

	float lDeltas[201];
	float rDeltas[201];

	for(int j = 0; j < 8; j++)
	{
		for(int i = 0; i < this->colNumbers; i++)
		{
			if(i > 0)
			{
				lDeltas[i] = this->spread * (this->columns.at(i)->returnHeight() - this->columns.at(i - 1)->returnHeight());
				this->columns.at(i - 1)->setSpeed(lDeltas[i]);
			}
			if(i < this->colNumbers - 1)
			{
				rDeltas[i] = this->spread * (this->columns.at(i)->returnHeight() - this->columns.at(i + 1)->returnHeight());
				this->columns.at(i + 1)->setSpeed(rDeltas[i]);
			}
		}

		for (int i = 0; i < this->colNumbers; i++)
		{
			if(i > 0)
				this->columns.at(i - 1)->setHeight(lDeltas[i]);
			if(i < this->colNumbers - 1)
				this->columns.at(i + 1)->setHeight(rDeltas[i]);
		}
	}

}

void Water::splash(int index, float speed)
{
	this->columns.at(index)->setSpeed(speed);
}

void Water::render()
{
	this->update();

	this->it = this->columns.begin();

	while(it != this->columns.end())
	{
		(*it)->render();
		this->it++;
	}
}