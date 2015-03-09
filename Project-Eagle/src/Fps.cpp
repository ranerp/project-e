#include "Fps.h"
#include <iostream>
#include <sstream>

using namespace std;

Fps::Fps(sf::RenderWindow &rw)
	: window(&rw)
{
	this->font.loadFromFile("fonts/arial.ttf");
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.move(this->window->getSize().x - 50, 15);
}

Fps::~Fps()
{
}

void Fps::show()
{
	this->frameRate = 1.f / this->clock.getElapsedTime().asSeconds();

	ostringstream ostr;

	ostr << this->frameRate;

	string str;

	str.append("Fps: ");
	str.append(ostr.str());

	this->text.setString(str);

	this->window->draw(this->text);

	this->clock.restart();
}